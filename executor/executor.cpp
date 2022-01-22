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

#include "../network/common.h"
#include "../network/eof.h"
#include "../network/field.h"
#include "../network/ok.h"

namespace uhp_sql {

redisContext* Executor::pmemRedisContext = nullptr;

bool Executor::Init(std::string pmemRedisIp, uint16_t pmemRedisPort) {
  redisReply* reply;
  // TODO: need to configurable
  struct timeval timeout = {1, 500000};  // 1.5 seconds
  pmemRedisContext =
      redisConnectWithTimeout(pmemRedisIp.c_str(), pmemRedisPort, timeout);

  if (pmemRedisContext == NULL || pmemRedisContext->err) {
    if (pmemRedisContext) {
      printf("Connection error: %s\n", pmemRedisContext->errstr);
      redisFree(pmemRedisContext);
    } else {
      printf("Connection error: can't allocate redis context\n");
    }
    return false;
  }
  return true;
}

bool Executor::Exec(hsql::SQLParserResult& result, Client* cli,
                    std::string& pack) {
  UnboundedBuffer reply_;
  for (size_t i = 0u; i < result.size(); ++i) {
    switch (result.getStatement(i)->type()) {
      // https://dev.mysql.com/doc/internals/en/protocoltext-resultset.html
      case hsql::kStmtSelect: {
        std::string res = ExecSelectStatement(
            (const hsql::SelectStatement*)result.getStatement(i), 0);
        std::cout << "run select result: " << res << "\n";
        uint8_t seq = 1;
        std::vector<uint8_t> feildCountPacket;
        feildCountPacket.push_back(1);
        feildCountPacket.push_back(0);
        feildCountPacket.push_back(0);
        feildCountPacket.push_back(seq);
        feildCountPacket.push_back(1);
        reply_.PushData(
            std::string(feildCountPacket.begin(), feildCountPacket.end())
                .c_str(),
            feildCountPacket.size());
        cli->SendPacket(reply_);
        reply_.Clear();

        seq++;
        Protocol::FieldPacket newFieldPack(
            "RAW DATA", static_cast<uint32_t>(TYPE_VARCHAR), "test", "test",
            "db", "RAW DATA", 80, CHARACTER_SET_UTF8, 0, 0);
        std::vector<uint8_t> fieldPack = newFieldPack.Pack();
        std::vector<uint8_t> outPack4;
        outPack4.push_back(fieldPack.size());
        outPack4.push_back(0);
        outPack4.push_back(0);
        outPack4.push_back(seq);
        outPack4.insert(outPack4.end(), fieldPack.begin(), fieldPack.end());
        reply_.PushData(std::string(outPack4.begin(), outPack4.end()).c_str(),
                        outPack4.size());
        cli->SendPacket(reply_);
        reply_.Clear();

        seq++;
        Protocol::EofPacket eof(0, 2);
        std::vector<uint8_t> eofPacket = eof.Pack();
        std::vector<uint8_t> outPackNew;
        outPackNew.push_back(eofPacket.size());
        outPackNew.push_back(0);
        outPackNew.push_back(0);
        outPackNew.push_back(seq);
        outPackNew.insert(outPackNew.end(), eofPacket.begin(), eofPacket.end());
        reply_.PushData(
            std::string(outPackNew.begin(), outPackNew.end()).c_str(),
            outPackNew.size());
        cli->SendPacket(reply_);
        reply_.Clear();

        seq++;
        std::vector<std::string> row;
        row.push_back(res);
        Protocol::RowPacket rowPack(row);
        std::vector<uint8_t> rowPacket = rowPack.Pack();
        std::vector<uint8_t> outPack;
        outPack.push_back(rowPacket.size());
        outPack.push_back(0);
        outPack.push_back(0);
        outPack.push_back(seq);
        outPack.insert(outPack.end(), rowPacket.begin(), rowPacket.end());
        reply_.PushData(std::string(outPack.begin(), outPack.end()).c_str(),
                        outPack.size());
        cli->SendPacket(reply_);
        reply_.Clear();

        seq++;
        Protocol::EofPacket eofBack(0, 2);
        std::vector<uint8_t> eofBackPacket = eofBack.Pack();
        std::vector<uint8_t> outPack1;
        outPack1.push_back(eofBackPacket.size());
        outPack1.push_back(0);
        outPack1.push_back(0);
        outPack1.push_back(seq);
        outPack1.insert(outPack1.end(), eofBackPacket.begin(),
                        eofBackPacket.end());
        reply_.PushData(std::string(outPack1.begin(), outPack1.end()).c_str(),
                        outPack1.size());
        cli->SendPacket(reply_);
        reply_.Clear();
        break;
      }
      case hsql::kStmtInsert: {
        uint64_t ret = ExecInsertStatement(
            (const hsql::InsertStatement*)result.getStatement(i), 0);
        Protocol::OkPacket okPack;
        std::vector<uint8_t> outPut = okPack.Pack(ret, 0, 2, 0);
        std::vector<uint8_t> res;
        res.push_back(outPut.size());
        res.push_back(0);
        res.push_back(0);
        res.push_back(1);
        res.insert(res.end(), outPut.begin(), outPut.end());
        reply_.PushData(std::string(res.begin(), res.end()).c_str(),
                        res.size());
        cli->SendPacket(reply_);
        reply_.Clear();
        break;
      }
      case hsql::kStmtDelete: {
        ExecDeleteStatement(
            (const hsql::DeleteStatement*)result.getStatement(i), 0);
        break;
      }
      case hsql::kStmtUpdate: {
        ExecUpdateStatement(
            (const hsql::UpdateStatement*)result.getStatement(i), 0);
        break;
      }
      default: {
        Protocol::OkPacket okPack;
        std::vector<uint8_t> outPut = okPack.Pack(0, 0, 2, 1);
        outPut[3] = pack[3] + 1;
        reply_.PushData(std::string(outPut.begin(), outPut.end()).c_str(),
                        outPut.size());
        cli->SendPacket(reply_);
        reply_.Clear();
      }
    }
  }
  return true;
}

Executor::Executor() {}

Executor::~Executor() {}

bool Executor::AnalyzeCreateTableStatement(const hsql::CreateStatement* stmt,
                                           std::string& tabName,
                                           std::vector<TableColumn>& colDefs) {}

uint64_t Executor::CreateTableMetaToPMemKV(std::string& tabName,
                                           std::vector<TableColumn>& colDefs) {}

bool Executor::SendCreateTableResultToClient(Client* cli, uint8_t affectRows) {}

bool Executor::AnalyzeSelectStatement(hsql::SelectStatement* stmt,
                                      hsql::OperatorType& opType,
                                      std::string& queryTab,
                                      std::string& queryFeild,
                                      std::string& queryValue, uint64_t& limit,
                                      uint64_t& offset) {}

std::vector<std::vector<TableColumn> > Executor::SelectRowsFromPMemKV(
    hsql::OperatorType& opType, std::string& queryTab, std::string& queryFeild,
    std::string& queryValue, uint64_t& limit, uint64_t& offset) {}

bool Executor::SendResultToClient(
    Client* cli, std::vector<std::vector<TableColumn> >& resultSet) {}

bool Executor::AnalyzeInsertStatement(const hsql::InsertStatement* stmt,
                                      std::string& tabName,
                                      std::vector<TableColumn>& resultSet) {}

uint64_t Executor::InsertRowToPMemKV(std::string& tabName,
                                     std::vector<TableColumn>& row) {}

bool Executor::SendInsertAffectRowsToClient(Client* cli, uint64_t affectRows) {}

bool Executor::AnalyzeUpdateStatement(const hsql::UpdateStatement* stmt,
                                      std::string& tabName, std::string& column,
                                      std::string& value,
                                      hsql::OperatorType& opType,
                                      std::string& queryFeild,
                                      std::string& queryValue) {}

uint64_t Executor::UpdateRowInPMemKV(std::string& tabName, std::string& column,
                                     std::string& value,
                                     hsql::OperatorType& opType,
                                     std::string& queryFeild,
                                     std::string& queryValue) {}

bool Executor::SendUpdateAffectRowsToClient(Client* cli, uint16_t affectRows) {}

bool Executor::AnalyzeDeleteStatement(const hsql::DeleteStatement* stmt,
                                      std::string& tabName,
                                      hsql::OperatorType& opType,
                                      std::string& queryFeild,
                                      std::string& queryValue) {}

uint64_t Executor::DeleteRowsInPMemKV(std::string& tabName,
                                      hsql::OperatorType& opType,
                                      std::string& queryFeild,
                                      std::string& queryValue) {}

bool Executor::SendDeleteAffectRowsToClient(Client* cli, uint64_t affectRows) {}

bool Executor::OpenTableInPMemKV(std::string newTab) {}

bool Executor::DropTableInPMemKV(std::string tabName) {}

}  // namespace uhp_sql
