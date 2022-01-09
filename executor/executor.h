// Copyright 2015 The uhp-sql Authors
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//

#include <stdint.h>

#include <iostream>
#include <string>

#include "../parser/sql_parser.h"
#include "../third_party/libredis/hiredis.h"
// contains printing utilities
#include "../network/client.h"
#include "../network/unbounded_buffer.h"
#include "../parser/sqlhelper.h"

namespace uhp_sql {

class Executor {
 public:
  static bool Init(std::string pmemRedisIp, uint16_t pmemRedisPort);

  // TODO: replace std:string to a real obj for network repl
  static bool Exec(hsql::SQLParserResult& result, Client* cli,
                   std::string& pack);

  static std::string ExecSelectStatement(const hsql::SelectStatement* stmt,
                                         uintmax_t numIndent);

  static uint64_t ExecInsertStatement(const hsql::InsertStatement* stmt,
                                      uintmax_t numIndent);

  static std::string ExecCreateStatement(const hsql::CreateStatement* stmt,
                                         uintmax_t numIndent);

  static std::string ExecUpdateStatement(const hsql::UpdateStatement* stmt,
                                         uintmax_t numIndent);

  static std::string ExecDeleteStatement(const hsql::DeleteStatement* stmt,
                                         uintmax_t numIndent);

  Executor();

  ~Executor();

 private:
  static redisContext* pmemRedisContext;
};

}  // namespace uhp_sql
