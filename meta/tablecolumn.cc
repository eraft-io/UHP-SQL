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

#include "tablecolumn.h"

namespace uhp_sql {

TableColumn::TableColumn(std::string col_name, hsql::DataType col_type)
    : col_name_(col_name), col_type_(col_type) {
  val_ = "";
}

TableColumn::TableColumn(std::string col_name, hsql::DataType col_type,
                         std::string val)
    : col_name_(col_name), col_type_(col_type), val_(val) {}

TableColumn::~TableColumn() {}

std::string TableColumn::GetColName() { return col_name_; }
int TableColumn::GetColType() { return hsql::DataType2Int(col_type_); }
hsql::DataType TableColumn::GetColTyp() { return col_type_; }
std::string TableColumn::GetVal() { return val_; }

}  // namespace uhp_sql