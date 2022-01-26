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
#ifndef META_DBMS_H
#define META_DBMS_H

#include <iostream>
#include <map>
#include <string>
#include <unordered_map>
#include <vector>

#include "database.h"

namespace uhp_sql {

struct PeerAddr {
  PeerAddr(std::string ip_, int32_t port_) : ip(ip_), port(port_) {}
  std::string ip;
  int32_t port;
};

class DBMS {
 public:
  DBMS();
  ~DBMS();
  bool CreateDataBase(std::string db_name);
  bool OpenDataBase(std::string db_name);
  bool DropDataBase(std::string db_name);

  bool RecoverFromPmemKV();
  std::vector<std::string> ShowDataBases();
  DataBase* GetCurDB();
  bool SwitchDB(std::string db_name);

 private:
  std::unordered_map<std::string, DataBase*> dbs_;

  DataBase* cur_db_;

  std::map<int, PeerAddr> clients_;
};

}  // namespace uhp_sql

#endif  // META_DBMS_H