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
#include "../network/string_utils.h"

namespace uhp_sql {

bool Executor::AnalyzeInsertStatement(const hsql::InsertStatement* stmt,
                                      std::string& tabName,
                                      std::vector<TableColumn>& resultSet) {
  tabName = std::string(stmt->tableName);
  std::vector<std::string> columnNames;
  for (char* colName : *stmt->columns) {
    columnNames.push_back(std::string(colName));
  }
  std::vector<std::string> colValues;
  for (hsql::Expr* expr : *stmt->values) {
    switch (expr->type) {
      case hsql::kExprLiteralString: {
        colValues.push_back(expr->name);
        break;
      }
      case hsql::kExprLiteralInt: {
        colValues.push_back(std::to_string(expr->ival));
        break;
      }
    }
  }
  for (uint64_t i = 0; i < columnNames.size(); i++) {
    // TODO: get coltype with table name and col name
    TableColumn tabCol(columnNames[i], hsql::DataType::UNKNOWN, colValues[i]);
    resultSet.push_back(tabCol);
  }
  return true;
}

uint64_t Executor::InsertRowToPMemKV(std::string& tabName,
                                     std::vector<TableColumn>& row) {
  if(row.size() == 0) {
    return 0;
  }
  std::string dbName =  DBMS().GetCurDB()->GetDbName();
  std::string key = dbName + "_" + tabName + "_p_" + row[0].GetVal();
  std::vector<std::string> vals;
  for(auto& col: row) {
    vals.push_back(col.GetVal());
  }
  std::string value = StringsJoin(vals, "$$");
  auto reply = static_cast<redisReply*>(
      redisCommand(Executor::pmemRedisContext, "SET %s %s", key.c_str(), value.c_str()));
  freeReplyObject(reply);
  return 0;
}

bool Executor::SendInsertAffectRowsToClient(Client* cli, uint8_t seq, uint64_t affectRows) {
  SendOkMessageToClient(cli, seq, affectRows, 0, 2, 1);
  return true;
}

}  // namespace uhp_sql
