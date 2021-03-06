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

#include <iostream>

#include "../executor/executor.h"
#include "../network/common.h"
#include "../third_party/libredis/hiredis.h"

namespace uhp_sql {

DBMS::DBMS() {
  cur_db_ = nullptr;
  RecoverFromPmemKV();
}

DBMS::~DBMS() {}

bool DBMS::CreateDataBase(std::string db_name) {
  DataBase* newdb = new DataBase(db_name, false);
  dbs_.insert(std::make_pair(db_name, newdb));
  std::string key = "database_" + db_name;
  auto reply = static_cast<redisReply*>(redisCommand(
      Executor::GetContext(), "SET %s %s", key.c_str(), db_name.c_str()));
  freeReplyObject(reply);
  std::cout << "create database " << db_name << " ok! " << std::endl;
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

bool DBMS::HasTable(std::string tab_name) {
  DataTable* resTable = cur_db_->GetTable(tab_name);
  if(resTable == nullptr) {
    return false;
  }
  return true;
}

bool DBMS::DropDataBase(std::string db_name) {
  std::unordered_map<std::string, DataBase*>::iterator iter;
  iter = dbs_.find(db_name);
  std::string value = "";
  if (iter != dbs_.end()) {
    auto reply = static_cast<redisReply*>(redisCommand(
        Executor::GetContext(), "SET %s %s", db_name.c_str(), value.c_str()));
    freeReplyObject(reply);
  }
  return true;
}

bool DBMS::RecoverFromPmemKV() {
  std::cout << "DBMS::RecoverFromPmemKV" << std::endl;
  redisReply* reply = (redisReply*)redisCommand(Executor::GetContext(),
                                                "SCAN 0 MATCH database_*");
  if (reply->element != nullptr) {
    if (reply->element[1]->elements == 0) {
      CreateDataBase(DEFAULT_DATABASE_NAME);
      SwitchDB(DEFAULT_DATABASE_NAME);
      return false;
    }
    for (int i = 0; i < reply->element[1]->elements;) {
      std::string key = reply->element[1]->element[i++]->str;
      std::string dbname = reply->element[1]->element[i++]->str;
      std::cout << "database recover " << key << " dbname: " << dbname
                << std::endl;
      DataBase* newdb = new DataBase(dbname, true);
      dbs_.insert(std::make_pair(dbname, newdb));
      cur_db_ = newdb;
    }
    if (reply) {
      freeReplyObject(reply);
    }
  }
  return false;
}

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
    std::cout << "switch to database " << db_name << " ok! " << std::endl;
  } else {
    std::cout << "Switch DB failed!\n";
    return false;
  }
  return true;
}

}  // namespace uhp_sql