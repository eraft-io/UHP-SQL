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

#include "../network/stream_socket.h"
#include "../network/string_utils.h"
#include "executor.h"

namespace uhp_sql {

bool Executor::AnalyzeSelectStatement(const hsql::SelectStatement* stmt,
                                      hsql::OperatorType& opType,
                                      std::string& queryTab,
                                      std::string& queryFeild,
                                      std::string& queryValue, uint64_t& limit,
                                      uint64_t& offset) {
  queryTab = stmt->fromTable->name;
  hsql::Expr* expr = stmt->whereClause;
  if (!expr) {
    // SELECT * FROM tab; scan all data
    return false;
  }
  switch (expr->type) {
    case hsql::kExprOperator: {
      opType = expr->opType;
      queryFeild = expr->expr->name;
      queryValue = expr->expr2->name;
      break;
    }
    default:
      break;
  }
  return true;
}

std::vector<std::vector<TableColumn> > Executor::SelectRowsFromPMemKV(
    hsql::OperatorType& opType, std::string& queryTab, std::string& queryFeild,
    std::string& queryValue, uint64_t& limit, uint64_t& offset) {
  std::vector<std::vector<TableColumn> > rows;
  switch (opType) {
    case hsql::kOpEquals: {
      std::string dbName = Executor::dbmsContext->GetCurDB()->GetDbName();
      std::string key = "data_" + dbName + "_" + queryTab + "_p_" + queryValue;
      std::string result;
      redisReply* reply = static_cast<redisReply*>(
          redisCommand(pmemRedisContext, "GET %s", key.c_str()));
      if (reply->str != nullptr) {
        result = std::string(reply->str);
        freeReplyObject(reply);
      }
      std::cout << "select res: " << result << std::endl;
      std::vector<std::string> cols = StringSplit(result, "$$");
      std::map<int, std::string> indexColMap = Executor::dbmsContext->GetCurDB()
                        ->GetTable(queryTab)
                        ->GetIndexColMap();
      std::vector<TableColumn> row;
      for (uint64_t i = 0; i < cols.size(); i++) {
        TableColumn newCol(indexColMap[i], Executor::dbmsContext->GetCurDB()->GetTable(queryTab)->GetColType(indexColMap[i]), cols[i]);
        row.push_back(std::move(newCol));
      }
      rows.push_back(row);
      break;
    }
    default:
      break;
  }
  return rows;
}

bool Executor::SendResultSetToClient(
    Client* cli, uint8_t seq,
    std::vector<std::vector<TableColumn> >& resultSet) { 
     std::cout << "res name : " << resultSet[0][0].GetColName() << std::endl;
  
  SendOkMessageToClient(cli, seq, 0, 0, 2, 0);
  return true;
}

}  // namespace uhp_sql
