#include "executor.h"

namespace uhp_sql {

// CREATE TABLE User {
//     ID int,
//     Name varchar(20),
//     Role varchar(20),
//     Age int,
//     PRIMARY KEY (ID),
//     KEY idxAge (Age)
// };
//
// 1, "TiDB", "SQL Layer", 10
// 2, "TiKV", "KV Engine", 20
// 3, "PD", "Manager", 30
//
// t[tableName]_r(rowKeyID) -> Tuple
//
// tUser_r1 --> ["TiDB", "SQL Layer", 10]
// tUser_r2 --> ["TiKV", "KV Engine", 20]
// tUser_r3 --> ["PD", "Manager", 30]

uint64_t Executor::ExecInsertStatement(const hsql::InsertStatement* stmt,
                                       uintmax_t numIndent) {
  std::string tableName = stmt->tableName;
  std::vector<std::string> cols;
  std::vector<std::string> colsValues;
  for (char* colName : *stmt->columns) {
    cols.push_back(colName);
  }
  switch (stmt->type) {
    case hsql::kInsertValues: {
      for (hsql::Expr* expr : *stmt->values) {
        if (!expr) {
          return 0;
        }
        switch (expr->type) {
          case hsql::kExprLiteralString: {
            colsValues.push_back(expr->name);
            break;
            case hsql::kExprLiteralInt: {
              colsValues.push_back(std::to_string(expr->ival));
            }
          }
          default:
            break;
        }
      }
      break;
    }
    case hsql::kInsertSelect: {
      break;
    }
    default:
      break;
  }

  std::string rowKey = std::string("t_" + tableName + "_r_" + colsValues[0]);
  std::string rowVal;
  for (auto col : colsValues) {
    rowVal += col + ",";
  }

  // write to db
  auto reply = static_cast<redisReply*>(redisCommand(
      pmemRedisContext, "SET %s %s", rowKey.c_str(), rowVal.c_str()));
  freeReplyObject(reply);

  return 1;
}

}  // namespace uhp_sql
