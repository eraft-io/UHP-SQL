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

#include "dbms.h"

#include "../executor/executor.h"
#include "hiredis/hiredis.h"

namespace uhp_sql {

redisContext* DBMS::pmemRedisContext = uhp_sql::Executor::GetContext();

DBMS::DBMS() {
  cur_db_ = nullptr;
  RecoverFromPmemKV();
}

DBMS::~DBMS() {}

bool DBMS::CreateDataBase(std::string db_name) {
  DataBase* newdb = new DataBase(db_name);
  dbs_.insert(std::make_pair(db_name, newdb));
  std::string key = "database_" + db_name;
  auto reply = static_cast<redisReply*>(redisCommand(
      pmemRedisContext, "SET %s %s", key.c_str(), db_name.c_str()));
  freeReplyObject(reply);
  return true;
}

bool DBMS::OpenDataBase(std::string db_name) {
  std::unordered_map<std::string, DataBase*>::iterator iter;
  iter = dbs_.find(db_name);
  if (iter != dbs_.end()) {
    cur_db_ = iter->second;
    return true;
  } else {
    return false;
  }
}

bool DBMS::DropDataBase(std::string db_name) {
  std::unordered_map<std::string, DataBase*>::iterator iter;
  iter = dbs_.find(db_name);
  if (iter != dbs_.end()) {
    auto reply = static_cast<redisReply*>(redisCommand(
        pmemRedisContext, "SET %s %s", key.c_str(), db_name.c_str()));
    freeReplyObject(reply);
  }
}

bool DBMS::RecoverFromPmemKV() {}

DataBase* DBMS::GetCurDB() { return cur_db_; }

std::vector<std::string> DBMS::ShowDataBases() {
  std::vector<std::string> ans;
  for (std::unordered_map<std::string, DataBase*>::iterator iter = dbs_.begin();
       iter != dbs_.end(); ++iter) {
    std::cout << iter->first << '\n';
    ans.push_back(iter->first);
  }
  return ans;
}

bool DBMS::SwitchDB(std::string db_name) {
  std::unordered_map<std::string, DataBase*>::iterator iter;
  iter = dbs_.find(db_name);
  if (iter != dbs_.end()) {
    cur_db_ = iter->second;
  } else {
    std::cout << "Switch DB failed!\n";
    return false;
  }
}

}  // namespace uhp_sql