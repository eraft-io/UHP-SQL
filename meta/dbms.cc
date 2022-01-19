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

namespace uhp_sql {

DBMS::DBMS() {}

DBMS::~DBMS() {}

bool DBMS::OpenDataBase(std::string db_name) {}

bool DBMS::DropDataBase(std::string db_name) {}

bool DBMS::RecoverFromPmemKV() {}

std::vector<std::string> DBMS::ShowDataBases() {}

DataBase* DBMS::SwitchDB(std::string db_name) {}

}  // namespace uhp_sql