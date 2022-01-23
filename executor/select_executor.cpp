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

bool Executor::AnalyzeSelectStatement(const hsql::SelectStatement* stmt,
                                      hsql::OperatorType& opType,
                                      std::string& queryTab,
                                      std::string& queryFeild,
                                      std::string& queryValue, uint64_t& limit,
                                      uint64_t& offset) {
  std::string tablename = stmt->fromTable->name;
  hsql::Expr* expr = stmt->whereClause;
  if (!expr) return false;
  switch (expr->type) {
    case kExprColumnRef:

      break;
  }
  return true;
}

std::vector<std::vector<TableColumn> > Executor::SelectRowsFromPMemKV(
    hsql::OperatorType& opType, std::string& queryTab, std::string& queryFeild,
    std::string& queryValue, uint64_t& limit, uint64_t& offset) {
  std::vector<std::vector<TableColumn> > rows;
  return rows;
}

bool Executor::SendResultSetToClient(
    Client* cli, std::vector<std::vector<TableColumn> >& resultSet) {
  return true;
}

}  // namespace uhp_sql
