// Copyright 2022 The uhp-sql Authors
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

#include "client.h"

#include <stdint.h>
#include <sys/time.h>

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#include "auth.h"
#include "common.h"
#include "greeting.h"
#include "unbounded_buffer.h"
#include "err.h"
// include the sql parser
#include "../executor/executor.h"
#include "../parser/sql_parser.h"

// contains printing utilities
#include "../parser/sqlhelper.h"

PacketLength Client::_HandlePacket(const char *start, std::size_t bytes) {
  const char *const end = start + bytes;
  const char *ptr = start;
  Protocol::AuthPacket ap;
  std::vector<uint8_t> OkPacket = {7, 0, 0, 2, 0, 0, 0, 2, 0, 0, 0};
  OkPacket[3] = start[3] + 1;
  std::string pack = std::string(start, end);
  std::string queryStr = std::string(start + 5, end);

  if (pack[3] == INIT_PACKET_CNT) {
    auto authPkt = std::vector<uint8_t>(pack.begin() + 4, pack.end());
    ap.UnPack(authPkt);
    std::cout << "UserName: " << ap.GetUserName() << std::endl;
    std::cout << "PluginName: " << ap.GetPluginName() << std::endl;
    std::cout << "DataBaseName: " << ap.GetDatabaseName() << std::endl;
    reply_.PushData(std::string(OkPacket.begin(), OkPacket.end()).c_str(),
                    OkPacket.size());
    SendPacket(reply_);
    _Reset();
    return static_cast<PacketLength>(bytes);
  } else {
    if(queryStr != "select @@version_comment limit 1") {
        hsql::SQLParserResult result;
        hsql::SQLParser::parse(queryStr, &result);
        if (result.isValid()) {
          uhp_sql::Executor::Exec(result, this, pack);
        } else {
          uhp_sql::Executor::SendErrorMessageToClient(this, pack[3] + 1, 50,  "ABCDE", std::string(result.errorMsg()));
        }
    } else {
        std::vector<uint8_t> OkPacket = {7, 0, 0, 2, 0, 0, 0, 2, 0, 0, 0};
        OkPacket[3] = pack[3] + 1;
        reply_.PushData(std::string(OkPacket.begin(), OkPacket.end()).c_str(),
                        OkPacket.size());
        SendPacket(reply_);
        reply_.Clear();
    }

    return static_cast<PacketLength>(bytes);
  }
}

Client::Client() { _Reset(); }

void Client::_Reset() {
  parser_.Reset();
  reply_.Clear();
}

void Client::OnConnect() {
  std::cout << "new client comming!" << std::endl;
  std::vector<uint8_t> greetingPacket;

  Protocol::GreetingPacket gp(1, "UHP-SQL-v0.1");
  std::vector<uint8_t> outputPacket = gp.Pack();
  greetingPacket.push_back(outputPacket.size());
  greetingPacket.push_back(0x00);
  greetingPacket.push_back(0x00);
  greetingPacket.push_back(0x00);

  greetingPacket.insert(greetingPacket.end(), outputPacket.begin(),
                        outputPacket.end());
  reply_.PushData(
      std::string(greetingPacket.begin(), greetingPacket.end()).c_str(),
      greetingPacket.size());
  SendPacket(reply_);
  _Reset();
}
