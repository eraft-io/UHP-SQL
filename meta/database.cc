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
  RecoverFromPmemKV();
}

DataBase::~DataBase() {}

DataTable* DataBase::CreateTable(std::string table_name,
                                 std::vector<TableColumn>& cols) {
  DataTable* newtable = new DataTable(table_name, cols);
  tables_.insert(std::make_pair(table_name, newtable));
  table_count_++;
  std::string key = "table_" + db_name_ + "_" + table_name;
  std::string value;
  for (int i = 0; i < cols.size(); ++i) {
    value += cols[i].GetColName() + "^" + std::to_string(cols[i].GetColType());
    if (i != cols.size() - 1) {
      value += "$$";
    }
  }
  auto reply = static_cast<redisReply*>(
      redisCommand(pmemRedisContext, "SET %s %s", key.c_str(), value.c_str()));
  freeReplyObject(reply);
  return newtable;
}

bool DataBase::DropTable(std::string table_name) {
  std::string key = "table_" + db_name_ + "_" + table_name;
  std::string value = "";
  auto reply = static_cast<redisReply*>(
      redisCommand(pmemRedisContext, "SET %s %s", key.c_str(), value.c_str()));
  freeReplyObject(reply);
  table_count_--;
  return true;
}

bool DataBase::RecoverFromPmemKV() {
  std::string scankey = "table_" + db_name_ + "_*";
  redisReply* reply =
      (redisReply*)redisCommand(pmemRedisContext, "SCAN 0 MATCH %s", scankey);
  for (int i = 0; i < reply->element[1]->elements;) {
    std::string tablename = reply->element[1]->element[i++]->str;
    std::string table = reply->element[1]->element[i++]->str;
    std::vector<TableColumn> cols = GetColFromStr(table);
    DataTable* newtable = new DataTable(tablename, cols);
    tables_.insert(std::make_pair(tablename, newtable));
    table_count_++;
  }
  freeReplyObject(reply);
  return true;
}

std::vector<TableColumn> DataBase::GetColFromStr(std::string value) {
  std::vector<TableColumn> ans;
  std::string colname = "";
  std::string str = "";
  for (std::size_t i = 0; i < value.size(); ++i) {
    if (value[i] == '^') {
      colname = str;
      str = "";
      continue;
    } else if (value[i] == '$') {
      hsql::DataType coltype = hsql::Int2DataType(std::stoi(str));
      TableColumn col(colname, coltype);
      ans.push_back(col);
      str = "";
      ++i;
      continue;
    }
    str += value[i];
  }
  hsql::DataType coltype = hsql::Int2DataType(std::stoi(str));
  TableColumn col(colname, coltype);
  ans.push_back(col);
  return ans;
}

DataTable* DataBase::GetTable(std::string table_name) {
  std::unordered_map<std::string, DataTable*>::iterator iter;
  iter = tables_.find(table_name);
  if (iter != tables_.end()) {
    return iter->second;
  } else {
    std::cout << "Don't have table: " + table_name + "\n";
    return nullptr;
  }
}

std::string DataBase::GetDbName() { return db_name_; }

}  // namespace uhp_sql