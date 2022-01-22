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

#ifndef META_DATATABLE_H
#define META_DATATABLE_H

#include <iostream>
#include <map>
#include <string>
#include <vector>

#include "tablecolumn.h"

namespace uhp_sql {

class DataTable {
 public:
  DataTable();
  ~DataTable();
  bool RecoverFromPmemKV();

 private:
  pmemkv::db* db_;

  std::vector<TableColumn> cols;
  std::map<std::string, hsql::DataType> type_map;  // <colName, type>
};

}  // namespace uhp_sql

#endif  // META_DATATABLE_H