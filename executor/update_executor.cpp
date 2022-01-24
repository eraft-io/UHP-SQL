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


bool Executor::AnalyzeUpdateStatement(const hsql::UpdateStatement* stmt,
                                      std::string& tabName, std::string& column,
                                      std::string& value,
                                      hsql::OperatorType& opType,
                                      std::string& queryFeild,
                                      std::string& queryValue) {
  tabName = std::string(stmt->table->name);
  std::cout << "update size: " << (*stmt->updates).size() << std::endl;
  if(stmt->updates->size() == 0) {
    return false;
  }
  column = std::string((*stmt->updates)[0]->column);
  value = std::string((*stmt->updates)[0]->value->name);
  switch(stmt->where->type) {
    case hsql::kExprStar: {
      break;
    }
    case hsql::kExprOperator: {
      opType = stmt->where->opType;
      queryFeild = stmt->where->expr->name;
      queryValue = stmt->where->expr2->name;
      break;
    }
  }
  return true;
}

uint64_t Executor::UpdateRowInPMemKV(std::string& tabName, std::string& column,
                                     std::string& value,
                                     hsql::OperatorType& opType,
                                     std::string& queryFeild,
                                     std::string& queryValue) {
                                       // TODO: check if queryFeild is primary key
  std::string dbName = Executor::dbmsContext->GetCurDB()->GetDbName();
  std::string key = "data_" + dbName + "_" + tabName + "_p_" + queryValue;
  std::string oValue;
  redisReply* reply = static_cast<redisReply*>(redisCommand(
    Executor::GetContext(), "GET %s", key.c_str()
  ));
  if(reply->str != nullptr){
    oValue = std::string(reply->str);
    freeReplyObject(reply);
  }
  std::vector<std::string> oCols = StringSplit(oValue, "$$");
  uint64_t index = Executor::dbmsContext->GetCurDB()->GetTable(tabName)->GetColIndex(column);
  oCols[index] = value;
  std::string nValue = StringsJoin(oCols, "$$");
  auto nReply = static_cast<redisReply*>(
      redisCommand(Executor::GetContext(), "SET %s %s", key.c_str(), nValue.c_str()));
  freeReplyObject(nReply);
  return 1;
}

bool Executor::SendUpdateAffectRowsToClient(Client* cli, uint8_t seq, uint16_t affectRows) {
  SendOkMessageToClient(cli, seq, affectRows, 0, 2, 1);
  return true;
}

}  // namespace uhp_sql
