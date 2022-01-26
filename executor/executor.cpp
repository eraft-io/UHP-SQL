// Copyright 2015 The uhp-sql Authors
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//

#include "executor.h"

#include <iostream>

#include "../network/common.h"
#include "../network/eof.h"
#include "../network/err.h"
#include "../network/field.h"
#include "../network/ok.h"

namespace uhp_sql {

redisContext* Executor::pmemRedisContext = nullptr;
DBMS* Executor::dbmsContext = nullptr;

bool Executor::Init(std::string pmem_redis_ip, uint16_t pmem_redis_port) {
  redisReply* reply;
  // TODO: need to configurable
  struct timeval timeout = {1, 500000};  // 1.5 seconds
  pmemRedisContext =
      redisConnectWithTimeout(pmem_redis_ip.c_str(), pmem_redis_port, timeout);

  if (pmemRedisContext == NULL || pmemRedisContext->err) {
    if (pmemRedisContext) {
      printf("Connection error: %s\n", pmemRedisContext->errstr);
      redisFree(pmemRedisContext);
    } else {
      printf("Connection error: can't allocate redis context\n");
    }
    return false;
  }

  std::cout << "connect to pmem redis ok! " << std::endl;
  auto pmemkvReply = static_cast<redisReply*>(redisCommand(
      Executor::GetContext(), "SET %s %s", "pmemaddr", pmem_redis_ip.c_str()));
  freeReplyObject(pmemkvReply);
  dbmsContext = new DBMS();
  // create default db and switch to it

  return true;
}

bool Executor::Exec(hsql::SQLParserResult& result, Client* cli,
                    std::string& pack) {
  UnboundedBuffer reply_;
  for (size_t i = 0u; i < result.size(); ++i) {
    switch (result.getStatement(i)->type()) {
      case hsql::kStmtCreate: {
        std::string createTableName;
        std::vector<TableColumn> colDefs;
        if (AnalyzeCreateTableStatement(
                (const hsql::CreateStatement*)result.getStatement(i),
                createTableName, colDefs)) {
          uint64_t affectRows =
              CreateTableMetaToPMemKV(createTableName, colDefs);
          SendCreateTableResultToClient(cli, pack[3] + 1, affectRows);
        } else {
          uhp_sql::Executor::SendErrorMessageToClient(
              cli, pack[3] + 1, 50, "ABCDE", "exec create table sql error");
        }
        break;
      }
      case hsql::kStmtSelect: {
        hsql::OperatorType opType;
        std::string queryTab;
        std::string queryFeild;
        std::string queryValue;
        uint64_t limit;
        uint64_t offset;
        bool scanAll = false;
        if (AnalyzeSelectStatement(
                (const hsql::SelectStatement*)result.getStatement(i), opType,
                queryTab, queryFeild, queryValue, limit, offset, scanAll)) {
          auto rows = SelectRowsFromPMemKV(opType, queryTab, queryFeild,
                                           queryValue, limit, offset, scanAll);
          SendResultSetToClient(cli, pack[3] + 1, rows, queryTab);
        } else {
          uhp_sql::Executor::SendErrorMessageToClient(
              cli, pack[3] + 1, 50, "ABCDE", "exec select sql error");
        }
        break;
      }
      case hsql::kStmtInsert: {
        std::string tabName;
        std::vector<TableColumn> row;
        if (AnalyzeInsertStatement(
                (const hsql::InsertStatement*)result.getStatement(i), tabName,
                row)) {
          auto affectRows = InsertRowToPMemKV(tabName, row);
          SendInsertAffectRowsToClient(cli, pack[3] + 1, affectRows);
        } else {
          uhp_sql::Executor::SendErrorMessageToClient(
              cli, pack[3] + 1, 50, "ABCDE", "exec insert sql error");
        }
        break;
      }
      case hsql::kStmtDelete: {
        std::string tabName;
        hsql::OperatorType opType;
        std::string queryFeild;
        std::string queryValue;
        if (AnalyzeDeleteStatement(
                (const hsql::DeleteStatement*)result.getStatement(i), tabName,
                opType, queryFeild, queryValue)) {
          auto affectRows =
              DeleteRowsInPMemKV(tabName, opType, queryFeild, queryValue);
          SendDeleteAffectRowsToClient(cli, pack[3] + 1, affectRows);
        } else {
          uhp_sql::Executor::SendErrorMessageToClient(
              cli, pack[3] + 1, 50, "ABCDE", "exec delete sql error");
        }
        break;
      }
      case hsql::kStmtUpdate: {
        std::string tabName;
        std::string column;
        std::string value;
        hsql::OperatorType opType;
        std::string queryFeild;
        std::string queryValue;
        if (AnalyzeUpdateStatement(
                (const hsql::UpdateStatement*)result.getStatement(i), tabName,
                column, value, opType, queryFeild, queryValue)) {
          auto affectRows = UpdateRowInPMemKV(tabName, column, value, opType,
                                              queryFeild, queryValue);
          SendUpdateAffectRowsToClient(cli, pack[3] + 1, affectRows);
        } else {
          uhp_sql::Executor::SendErrorMessageToClient(
              cli, pack[3] + 1, 50, "ABCDE", "exec update sql error");
        }
        break;
      }
      default: {
        SendOkMessageToClient(cli, pack[3] + 1, 0, 0, 2, 1);
      }
    }
  }
  return true;
}

void Executor::SendOkMessageToClient(Client* cli, uint8_t seq,
                                     uint64_t affected_rows,
                                     uint64_t last_insertID,
                                     uint16_t status_flags, uint16_t warnings) {
  UnboundedBuffer reply_;
  Protocol::OkPacket okPack;
  std::vector<uint8_t> outPut =
      okPack.Pack(affected_rows, last_insertID, status_flags, warnings);
  std::vector<uint8_t> headPack;
  headPack.push_back(outPut.size());
  headPack.push_back(0);
  headPack.push_back(0);
  headPack.push_back(seq);
  reply_.PushData(std::string(headPack.begin(), headPack.end()).c_str(),
                  headPack.size());
  reply_.PushData(std::string(outPut.begin(), outPut.end()).c_str(),
                  outPut.size());
  cli->SendPacket(reply_);
  reply_.Clear();
}

Executor::Executor() {}

Executor::~Executor() {}

bool Executor::OpenTableInPMemKV(std::string new_tab) { return true; }

bool Executor::DropTableInPMemKV(std::string tab_name) { return true; }

void Executor::SendErrorMessageToClient(Client* cli, uint8_t seq,
                                        uint16_t error_code,
                                        std::string sql_state,
                                        std::string error_message) {
  Protocol::ErrPacket err;
  UnboundedBuffer reply_;
  std::vector<uint8_t> errPack = err.Pack(error_code, sql_state, error_message);
  std::vector<uint8_t> returnPack;
  uint8_t size = errPack.size();
  returnPack.push_back(size);
  returnPack.push_back(0);
  returnPack.push_back(0);
  returnPack.push_back(seq);
  returnPack.insert(returnPack.end(), errPack.begin(), errPack.end());
  reply_.PushData(std::string(returnPack.begin(), returnPack.end()).c_str(),
                  returnPack.size());
  cli->SendPacket(reply_);
  reply_.Clear();
}

redisContext* Executor::GetContext() { return pmemRedisContext; }

}  // namespace uhp_sql
