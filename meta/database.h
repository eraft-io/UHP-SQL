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

#ifndef META_DATABASE_H
#define META_DATABASE_H

#include <atomic>
#include <iostream>
#include <string>
#include <unordered_map>

#include "../third_party/libredis/hiredis.h"
#include "datatable.h"
#include "tablecolumn.h"

namespace uhp_sql {

class DataBase {
 public:
  DataBase(std::string db_name);
  ~DataBase();
  DataTable* CreateTable(std::string table_name,
                         std::vector<TableColumn>& cols);

  bool DropTable(std::string table_name);
  bool RecoverFromPmemKV();
  DataTable* GetTable(std::string table_name);

 private:
  static redisContext* pmemRedisContext;

  std::atomic<int> table_count_;

  std::string db_name_;

  std::unordered_map<std::string, DataTable*>
      tables_;  //<tableName, DataTable*>
};

}  // namespace uhp_sql

#endif  // META_DATABASE_H