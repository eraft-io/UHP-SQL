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

#include "database.h"

#include "../executor/executor.h"

namespace uhp_sql {

redisContext* DataBase::pmemRedisContext = uhp_sql::Executor::GetContext();

DataBase::DataBase(std::string db_name) : db_name_(db_name) {
  table_count_ = 0;
}

DataBase::~DataBase() {}

DataTable* DataBase::CreateTable(std::string& table_name,
                                 std::vector<TableColumn>& cols) {
  DataTable* newtable = new DataTable(table_name, cols);
  tables_.insert(std::make_pair(table_name, newtable));
  table_count_++;
  std::string key = "table_" + db_name_ + "_" + table_name;
  std::string value;
  for (auto iter = cols.begin(); iter != cols.end(); ++iter) {
    value += iter.col_name_ + "^" + std::to_string(iter.col_type_) + "$$";
  }
  auto reply = static_cast<redisReply*>(redisCommand(
      pmemRedisContext, "SET %s %s", key.c_str(), table_name.c_str()));
  freeReplyObject(reply);
}

bool DataBase::DropTable(std::string table_name) {}

bool DataBase::RecoverFromPmemKV() {}

DataTable* DataBase::GetTable(std::string table_name) {}

}  // namespace uhp_sql