/*
   Copyright 2022 eraft group

   Licensed under the Apache License, Version 2.0 (the "License");
   you may not use this file except in compliance with the License.
   You may obtain a copy of the License at

       http://www.apache.org/licenses/LICENSE-2.0

   Unless required by applicable law or agreed to in writing, software
   distributed under the License is distributed on an "AS IS" BASIS,
   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
   See the License for the specific language governing permissions and
   limitations under the License.
*/

#include "datatable.h"

#include "../executor/executor.h"

namespace uhp_sql {

redisContext* DataTable::pmemRedisContext = uhp_sql::Executor::GetContext();

DataTable::DataTable(std::string table_name, std::vector<TableColumn>& cols) {
  table_name_ = table_name;
  for (int i = 0; i < cols.size(); ++i) {
    cols.push_back(cols[i]);
    col_type_[cols[i].GetColName()] = cols[i].GetColTyp();
    col_index_[cols[i].GetColName()] = i;
  }
}

DataTable::~DataTable() {}

bool DataTable::RecoverFromPmemKV() {}

int DataTable::GetColIndex(std::string col_name) {
  std::map<std::string, int>::iterator it;
  it = col_index_.find(col_name);
  if (it != col_index_.end()) {
    return it->second;
  }
  return -1;
}

hsql::DataType DataTable::GetColType(std::string col_name) {
  std::map<std::string, hsql::DataType>::iterator it;
  it = col_type_.find(col_name);
  if (it != col_type_.end()) {
    return it->second;
  }
  return hsql::DataType::VARCHAR;
}

std::string DataTable::GetTableName() { return table_name_; }

}  // namespace uhp_sql