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

#ifndef META_TABLECOLUMN_H
#define META_TABLECOLUMN_H

#include <iostream>
#include <string>

#include "../parser/column_type.h"

namespace uhp_sql {

class TableColumn {
 public:
  TableColumn(std::string col_name, hsql::DataType col_type);

  TableColumn(std::string col_name, hsql::DataType col_type,
              std::string val);  // Value val
  ~TableColumn();

  std::string GetColName();
  int GetColType();
  hsql::DataType GetColTyp();
  std::string GetVal();

 private:
  std::string col_name_;

  hsql::DataType col_type_;

  std::string val_;  // Value val
};

}  // namespace uhp_sql

#endif  // META_TABLECOLUMN_H