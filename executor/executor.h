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

#include <stdint.h>

#include <iostream>
#include <string>

#include "../parser/sql_parser.h"
#include "../third_party/libredis/hiredis.h"
// contains printing utilities
#include "../meta/dbms.h"
#include "../meta/tablecolumn.h"
#include "../network/client.h"
#include "../network/unbounded_buffer.h"
#include "../parser/sqlhelper.h"

namespace uhp_sql {

class Executor {
 public:
  static bool Init(std::string pmemRedisIp, uint16_t pmemRedisPort);

  static bool Exec(hsql::SQLParserResult& result, Client* cli,
                   std::string& pack);

  static bool AnalyzeCreateTableStatement(const hsql::CreateStatement* stmt,
                                          std::string& tabName,
                                          std::vector<TableColumn>& colDefs);

  static uint64_t CreateTableMetaToPMemKV(std::string& tabName,
                                          std::vector<TableColumn>& colDefs);

  static void SendCreateTableResultToClient(Client* cli, uint8_t seq,
                                            uint8_t affectRows);

  static bool AnalyzeSelectStatement(const hsql::SelectStatement* stmt,
                                     hsql::OperatorType& opType,
                                     std::string& queryTab,
                                     std::string& queryFeild,
                                     std::string& queryValue, uint64_t& limit,
                                     uint64_t& offset);

  static std::vector<std::vector<TableColumn> > SelectRowsFromPMemKV(
      hsql::OperatorType& opType, std::string& queryTab,
      std::string& queryFeild, std::string& queryValue, uint64_t& limit,
      uint64_t& offset);

  static bool SendResultSetToClient(
      Client* cli, std::vector<std::vector<TableColumn> >& resultSet);

  static bool AnalyzeInsertStatement(const hsql::InsertStatement* stmt,
                                     std::string& tabName,
                                     std::vector<TableColumn>& resultSet);

  static uint64_t InsertRowToPMemKV(std::string& tabName,
                                    std::vector<TableColumn>& row);

  static bool SendInsertAffectRowsToClient(Client* cli, uint8_t seq,
                                           uint64_t affectRows);

  static bool AnalyzeUpdateStatement(const hsql::UpdateStatement* stmt,
                                     std::string& tabName, std::string& column,
                                     std::string& value,
                                     hsql::OperatorType& opType,
                                     std::string& queryFeild,
                                     std::string& queryValue);

  static uint64_t UpdateRowInPMemKV(std::string& tabName, std::string& column,
                                    std::string& value,
                                    hsql::OperatorType& opType,
                                    std::string& queryFeild,
                                    std::string& queryValue);

  static bool SendUpdateAffectRowsToClient(Client* cli, uint8_t seq, uint16_t affectRows);

  static bool AnalyzeDeleteStatement(const hsql::DeleteStatement* stmt,
                                     std::string& tabName,
                                     hsql::OperatorType& opType,
                                     std::string& queryFeild,
                                     std::string& queryValue);

  static uint64_t DeleteRowsInPMemKV(std::string& tabName,
                                     hsql::OperatorType& opType,
                                     std::string& queryFeild,
                                     std::string& queryValue);

  static bool SendDeleteAffectRowsToClient(Client* cli, uint8_t seq,
                                           uint64_t affectRows);

  static bool OpenTableInPMemKV(std::string newTab);

  static bool DropTableInPMemKV(std::string tabName);

  static void SendErrorMessageToClient(Client* cli, uint8_t seq,
                                       uint16_t errorCode, std::string sqlState,
                                       std::string errorMessage);

  static void SendOkMessageToClient(Client* cli, uint8_t seq,
                                    uint64_t affectedRows,
                                    uint64_t lastInsertID, uint16_t statusFlags,
                                    uint16_t warnings);

  static redisContext* GetContext();

  Executor();

  ~Executor();

 private:
  static redisContext* pmemRedisContext;

  static DBMS* dbmsContext;
};

}  // namespace uhp_sql
