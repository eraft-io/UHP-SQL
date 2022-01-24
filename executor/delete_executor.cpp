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
                                      std::string& tabName,
                                      hsql::OperatorType& opType,
                                      std::string& queryFeild,
                                      std::string& queryValue) {
  tabName = std::string(stmt->tableName);
  hsql::Expr* expr = stmt->expr;
  if (!expr) {
    // delete all data
    queryFeild = "1";
    queryValue = "1";
    opType = hsql::OperatorType::kOpEquals;
    return true;
  }
  switch (expr->type) {
    case hsql::kExprStar: {
      break;
    }
    case hsql::kExprOperator: {
      opType = expr->opType;
      queryFeild = expr->expr->name;
      queryValue = expr->expr2->name;
      break;
    }
  }
  return true;
}

uint64_t Executor::DeleteRowsInPMemKV(std::string& tabName,
                                      hsql::OperatorType& opType,
                                      std::string& queryFeild,
                                      std::string& queryValue) {
  uint64_t deletedRows = 0;
  std::string dbName = Executor::dbmsContext->GetCurDB()->GetDbName();
  switch (opType) {
    case hsql::OperatorType::kOpEquals: {
      // del all data
      std::string tabDataPrefix = "data_" + dbName + "_" + tabName + "_p_";
      if (queryFeild == "1" && queryValue == "1") {
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
      std::string delKey = tabDataPrefix + queryValue;
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
