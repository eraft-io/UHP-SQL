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
