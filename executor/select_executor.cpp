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
#include "executor.h"

namespace uhp_sql {

std::string Executor::ExecSelectStatement(const hsql::SelectStatement* stmt,
                                          uintmax_t numIndent) {
  std::string tableName = stmt->fromTable->name;
  hsql::OperatorType opType;
  std::string queryFeild, queryValue, result;
  hsql::Expr* expr = stmt->whereClause;
  if (!expr) {
    // return all data
    return "";
  }
  switch (expr->type) {
    case hsql::kExprStar: {
      break;
    }
    case hsql::kExprOperator: {
      std::cout << "op: " << expr->opType << std::endl;
      opType = expr->opType;
      std::cout << "queryFeild: " << expr->expr->name << std::endl;
      queryFeild = expr->expr->name;
      if (expr->expr2 != nullptr) {
        std::cout << "queryValue: " << expr->expr2->name << std::endl;
        queryValue = expr->expr2->name;
      }
      break;
    }
    default:
      break;
  }
  switch (opType) {
    case hsql::kOpEquals: {
      std::string queryKey = std::string("t_" + tableName + "_r_" + queryValue);
      redisReply* reply = static_cast<redisReply*>(redisCommand(
          pmemRedisContext, std::string("GET " + queryKey).c_str()));
      if (reply->str != nullptr) {
        result = std::string(reply->str);
        freeReplyObject(reply);
      }
      break;
    }
    default:
      break;
  }

  return result;
}

}  // namespace uhp_sql
