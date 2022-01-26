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
  static bool Init(std::string pmem_redis_ip, uint16_t pmem_redis_port);

  static bool Exec(hsql::SQLParserResult& result, Client* cli,
                   std::string& pack);

  static bool AnalyzeCreateTableStatement(const hsql::CreateStatement* stmt,
                                          std::string& tab_name,
                                          std::vector<TableColumn>& col_defs);

  static uint64_t CreateTableMetaToPMemKV(std::string& tab_name,
                                          std::vector<TableColumn>& col_defs);

  static void SendCreateTableResultToClient(Client* cli, uint8_t seq,
                                            uint8_t affect_rows);

  static bool AnalyzeSelectStatement(const hsql::SelectStatement* stmt,
                                     hsql::OperatorType& optype,
                                     std::string& query_tab,
                                     std::string& query_feild,
                                     std::string& query_value, uint64_t& limit,
                                     uint64_t& offset, bool& scan_all);

  static std::vector<std::vector<TableColumn> > SelectRowsFromPMemKV(
      hsql::OperatorType& op_type, std::string& query_tab,
      std::string& query_feild, std::string& query_value, uint64_t& limit,
      uint64_t& offset, bool& scan_all);

  static bool SendResultSetToClient(
      Client* cli, uint8_t seq,
      std::vector<std::vector<TableColumn> >& result_set,
      std::string& query_tab);

  static std::vector<TableColumn> DecodeRowResult(std::string res, std::string tab);

  static bool AnalyzeInsertStatement(const hsql::InsertStatement* stmt,
                                     std::string& tab_name,
                                     std::vector<TableColumn>& result_set);

  static uint64_t InsertRowToPMemKV(std::string& tab_name,
                                    std::vector<TableColumn>& row);

  static bool SendInsertAffectRowsToClient(Client* cli, uint8_t seq,
                                           uint64_t affect_rows);

  static bool AnalyzeUpdateStatement(const hsql::UpdateStatement* stmt,
                                     std::string& tab_name, std::string& column,
                                     std::string& value,
                                     hsql::OperatorType& op_type,
                                     std::string& query_feild,
                                     std::string& query_value);

  static uint64_t UpdateRowInPMemKV(std::string& tab_name, std::string& column,
                                    std::string& value,
                                    hsql::OperatorType& op_type,
                                    std::string& query_feild,
                                    std::string& query_value);

  static bool SendUpdateAffectRowsToClient(Client* cli, uint8_t seq,
                                           uint16_t affect_rows);

  static bool AnalyzeDeleteStatement(const hsql::DeleteStatement* stmt,
                                     std::string& tab_name,
                                     hsql::OperatorType& op_type,
                                     std::string& query_feild,
                                     std::string& query_value);

  static uint64_t DeleteRowsInPMemKV(std::string& tab_name,
                                     hsql::OperatorType& op_type,
                                     std::string& query_feild,
                                     std::string& query_value);

  static bool SendDeleteAffectRowsToClient(Client* cli, uint8_t seq,
                                           uint64_t affect_rows);

  static bool OpenTableInPMemKV(std::string new_tab);

  static bool DropTableInPMemKV(std::string tab_name);

  static void SendErrorMessageToClient(Client* cli, uint8_t seq,
                                       uint16_t error_code,
                                       std::string sql_state,
                                       std::string error_message);

  static void SendOkMessageToClient(Client* cli, uint8_t seq,
                                    uint64_t affected_rows,
                                    uint64_t last_insertID,
                                    uint16_t status_flags, uint16_t warnings);

  static redisContext* GetContext();

  Executor();

  ~Executor();

 private:
  static redisContext* pmemRedisContext;

  static DBMS* dbmsContext;
};

}  // namespace uhp_sql
