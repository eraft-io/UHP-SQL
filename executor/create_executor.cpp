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

#include <iostream>

#include "../meta/tablecolumn.h"
#include "../parser/column_type.h"
#include "executor.h"

namespace uhp_sql {

bool Executor::AnalyzeCreateTableStatement(const hsql::CreateStatement* stmt,
                                           std::string& tab_name,
                                           std::vector<TableColumn>& col_defs) {
  // parse create stmt
  tab_name = std::string(stmt->tableName);
  for (size_t i = 0; i < stmt->columns->size(); i++) {
    TableColumn colDef(std::string((*stmt->columns)[i]->name),
                       (*stmt->columns)[i]->type.data_type);
    col_defs.push_back(std::move(colDef));
  }
  return true;
}

uint64_t Executor::CreateTableMetaToPMemKV(std::string& tab_name,
                                           std::vector<TableColumn>& col_defs) {
  Executor::dbmsContext->GetCurDB()->CreateTable(tab_name, col_defs);
  return 1;
}

void Executor::SendCreateTableResultToClient(Client* cli, uint8_t seq,
                                             uint8_t affect_rows) {
  SendOkMessageToClient(cli, seq, affect_rows, 0, 2, 0);
}

}  // namespace uhp_sql
