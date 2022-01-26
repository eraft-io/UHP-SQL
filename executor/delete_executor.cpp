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

namespace uhp_sql {

bool Executor::AnalyzeDeleteStatement(const hsql::DeleteStatement* stmt,
                                      std::string& tab_name,
                                      hsql::OperatorType& op_type,
                                      std::string& query_feild,
                                      std::string& query_value) {
  tab_name = std::string(stmt->tableName);
  if(!Executor::dbmsContext->HasTable(tab_name)) {
    return false;
  }
  hsql::Expr* expr = stmt->expr;
  if (!expr) {
    // delete all data
    query_feild = "1";
    query_value = "1";
    op_type = hsql::OperatorType::kOpEquals;
    return true;
  }
  switch (expr->type) {
    case hsql::kExprStar: {
      break;
    }
    case hsql::kExprOperator: {
      op_type = expr->opType;
      query_feild = expr->expr->name;
      query_value = expr->expr2->name;
      break;
    }
  }
  return true;
}

uint64_t Executor::DeleteRowsInPMemKV(std::string& tab_name,
                                      hsql::OperatorType& op_type,
                                      std::string& query_feild,
                                      std::string& query_value) {
  uint64_t deletedRows = 0;
  std::string dbName = Executor::dbmsContext->GetCurDB()->GetDbName();
  switch (op_type) {
    case hsql::OperatorType::kOpEquals: {
      // del all data
      std::string tabDataPrefix = "data_" + dbName + "_" + tab_name + "_p_";
      if (query_feild == "1" && query_value == "1") {
        auto reply = (redisReply*)redisCommand(
            Executor::pmemRedisContext, "SCAN %d MATCH %s", 0, tabDataPrefix);
        for (uint64_t i = 0; i < reply->element[1]->elements * 2;) {
          std::string key = reply->element[1]->element[i]->str;
          auto delReply = (redisReply*)redisCommand(Executor::pmemRedisContext,
                                                    "DEL %s", key.c_str());
          freeReplyObject(delReply);
          i += 2;
        }
        freeReplyObject(reply);
      }
      // check query if query feild is primary key, if not return not support

      // support primary key equal del
      std::string delKey = tabDataPrefix + query_value;
      auto delReply = (redisReply*)redisCommand(Executor::GetContext(),
                                                "DEL %s", delKey.c_str());
      freeReplyObject(delReply);
      break;
    }
  }

  return 1;
}

bool Executor::SendDeleteAffectRowsToClient(Client* cli, uint8_t seq,
                                            uint64_t affectRows) {
  SendOkMessageToClient(cli, seq, affectRows, 0, 2, 1);
  return true;
}

}  // namespace uhp_sql
