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


bool Executor::AnalyzeUpdateStatement(const hsql::UpdateStatement* stmt,
                                      std::string& tabName, std::string& column,
                                      std::string& value,
                                      hsql::OperatorType& opType,
                                      std::string& queryFeild,
                                      std::string& queryValue) {
  return true;
}

uint64_t Executor::UpdateRowInPMemKV(std::string& tabName, std::string& column,
                                     std::string& value,
                                     hsql::OperatorType& opType,
                                     std::string& queryFeild,
                                     std::string& queryValue) {
  return 0;
}

bool Executor::SendUpdateAffectRowsToClient(Client* cli, uint8_t seq, uint16_t affectRows) {
  return true;
}

}  // namespace uhp_sql
