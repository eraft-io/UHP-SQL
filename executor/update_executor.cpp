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

bool Executor::AnalyzeUpdateStatement(const hsql::UpdateStatement* stmt,
                                      std::string& tab_name,
                                      std::string& column, std::string& value,
                                      hsql::OperatorType& op_type,
                                      std::string& query_feild,
                                      std::string& query_value) {
  tab_name = std::string(stmt->table->name);
  if (!Executor::dbmsContext->HasTable(tab_name)) {
    return false;
  }
  if (stmt->updates->size() == 0) {
    return false;
  }
  column = std::string((*stmt->updates)[0]->column);
  value = std::string((*stmt->updates)[0]->value->name);
  switch (stmt->where->type) {
    case hsql::kExprStar: {
      break;
    }
    case hsql::kExprOperator: {
      op_type = stmt->where->opType;
      query_feild = stmt->where->expr->name;
      query_value = stmt->where->expr2->name;
      break;
    }
  }
  return true;
}

uint64_t Executor::UpdateRowInPMemKV(std::string& tab_name, std::string& column,
                                     std::string& value,
                                     hsql::OperatorType& op_type,
                                     std::string& query_feild,
                                     std::string& query_value) {
  // TODO: check if query_feild is primary key
  std::string db_name = Executor::dbmsContext->GetCurDB()->GetDbName();
  std::string key = "data_" + db_name + "_" + tab_name + "_p_" + query_value;
  std::string o_value;
  redisReply* reply = static_cast<redisReply*>(
      redisCommand(Executor::GetContext(), "GET %s", key.c_str()));
  if (reply->str != nullptr) {
    o_value = std::string(reply->str);
    freeReplyObject(reply);
  } else {
    // no key find
    return 0;
  }
  std::vector<std::string> o_cols = StringSplit(o_value, "$$");
  uint64_t index =
      Executor::dbmsContext->GetCurDB()->GetTable(tab_name)->GetColIndex(
          column);
  o_cols[index] = value;
  std::string n_value = StringsJoin(o_cols, "$$");
  auto n_reply = static_cast<redisReply*>(redisCommand(
      Executor::GetContext(), "SET %s %s", key.c_str(), n_value.c_str()));
  freeReplyObject(n_reply);
  return 1;
}

bool Executor::SendUpdateAffectRowsToClient(Client* cli, uint8_t seq,
                                            uint16_t affectRows) {
  SendOkMessageToClient(cli, seq, affectRows, 0, 2, 1);
  return true;
}

}  // namespace uhp_sql
