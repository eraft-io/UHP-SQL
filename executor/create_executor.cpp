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
#include "../meta/tablecolumn.h"
#include <iostream>
#include "../parser/column_type.h"

namespace uhp_sql {


bool Executor::AnalyzeCreateTableStatement(const hsql::CreateStatement* stmt,
                                           std::string& tabName,
                                           std::vector<TableColumn>& colDefs) {
  // parse create stmt
  tabName = std::string(stmt->tableName);
  std::cout << "analyze create table " << std::endl; 
  std::cout << "col size " << stmt->columns->size() << std::endl;
  // std::cout << "col 2 " << std::string(*stmt->columns[1]->name) << std::endl;

  for(size_t i = 0; i < stmt->columns->size(); i ++) {
      std::cout << "col " << std::string((*stmt->columns)[i]->name) << std::endl;
      std::cout << "col type " << std::to_string(DataType2Int((*stmt->columns)[i]->type.data_type)) << std::endl;
      TableColumn colDef(std::string((*stmt->columns)[i]->name), (*stmt->columns)[i]->type.data_type);
      colDefs.push_back(std::move(colDef));
  }

  return true;
}

uint64_t Executor::CreateTableMetaToPMemKV(std::string& tabName,
                                           std::vector<TableColumn>& colDefs) {
  // if not success return 0
  Executor::dbmsContext->GetCurDB()->CreateTable(tabName, colDefs);
  return 1;
}

void Executor::SendCreateTableResultToClient(Client* cli, uint8_t seq, uint8_t affectRows) {
  SendOkMessageToClient(cli, seq, affectRows, 0, 2, 0);
}

}  // namespace uhp_sql
