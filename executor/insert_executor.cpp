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

#include "../network/string_utils.h"
#include "executor.h"

namespace uhp_sql {

bool Executor::AnalyzeInsertStatement(const hsql::InsertStatement* stmt,
                                      std::string& tab_name,
                                      std::vector<TableColumn>& result_set) {
  tab_name = std::string(stmt->tableName);
  // check if table exists
  if (!Executor::dbmsContext->HasTable(tab_name)) {
    return false;
  }
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
    result_set.push_back(tabCol);
  }
  return true;
}

uint64_t Executor::InsertRowToPMemKV(std::string& tab_name,
                                     std::vector<TableColumn>& row) {
  if (row.size() == 0) {
    return 0;
  }
  std::string dbName = Executor::dbmsContext->GetCurDB()->GetDbName();
  std::string key = "data_" + dbName + "_" + tab_name + "_p_" + row[0].GetVal();
  std::vector<std::string> vals;
  auto dataTable = Executor::dbmsContext->GetCurDB()->GetTable(tab_name);
  vals.resize(dataTable->GetColCount());
  for (auto& col : row) {
    uint64_t index = dataTable->GetColIndex(
            col.GetColName());
    vals[index] = col.GetVal();
  }
  for (auto& val : vals) {
    if (val.empty()) {
      val = "NULL";
    }
  }
  std::string value = StringsJoin(vals, "$$");
  auto reply = static_cast<redisReply*>(redisCommand(
      Executor::pmemRedisContext, "SET %s %s", key.c_str(), value.c_str()));
  freeReplyObject(reply);
  return 1;
}

bool Executor::SendInsertAffectRowsToClient(Client* cli, uint8_t seq,
                                            uint64_t affect_rows) {
  SendOkMessageToClient(cli, seq, affect_rows, 0, 2, 0);
  return true;
}

}  // namespace uhp_sql
