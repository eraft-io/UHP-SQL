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

#include "executor.h"

#include "../network/common.h"
#include "../network/eof.h"
#include "../network/field.h"
#include "../network/ok.h"

namespace uhp_sql {

redisContext* Executor::pmemRedisContext = nullptr;

bool Executor::Init(std::string pmemRedisIp, uint16_t pmemRedisPort) {
  redisReply* reply;
  // TODO: need to configurable
  struct timeval timeout = {1, 500000};  // 1.5 seconds
  pmemRedisContext = redisConnectWithTimeout("172.17.0.2", 6379, timeout);

  if (pmemRedisContext == NULL || pmemRedisContext->err) {
    if (pmemRedisContext) {
      printf("Connection error: %s\n", pmemRedisContext->errstr);
      redisFree(pmemRedisContext);
    } else {
      printf("Connection error: can't allocate redis context\n");
    }
    return false;
  }
  return true;
}

bool Executor::Exec(hsql::SQLParserResult& result, Client* cli,
                    std::string& pack) {
  UnboundedBuffer reply_;
  for (size_t i = 0u; i < result.size(); ++i) {
    switch (result.getStatement(i)->type()) {
      case hsql::kStmtSelect: {
        std::string res = ExecSelectStatement(
            (const hsql::SelectStatement*)result.getStatement(i), 0);
        std::cout << "run select result: " << res << "\n";
        // 1
        std::vector<uint8_t> feildCountPacket;
        feildCountPacket.push_back(1);
        feildCountPacket.push_back(0);
        feildCountPacket.push_back(0);
        feildCountPacket.push_back(1);
        feildCountPacket.push_back(2);
        reply_.PushData(
            std::string(feildCountPacket.begin(), feildCountPacket.end())
                .c_str(),
            feildCountPacket.size());
        cli->SendPacket(reply_);
        reply_.Clear();

        // 2
        uint8_t seq = 2;
        Protocol::FieldPacket newFieldPack(
            "col", static_cast<uint32_t>(TYPE_VARCHAR), "test", "test", "db",
            "col", 80, CHARACTER_SET_UTF8, 0, 0);
        std::vector<uint8_t> fieldPack = newFieldPack.Pack();
        std::vector<uint8_t> outPack;
        outPack.push_back(fieldPack.size());
        outPack.push_back(0);
        outPack.push_back(0);
        outPack.push_back(seq);
        outPack.insert(outPack.end(), fieldPack.begin(), fieldPack.end());
        reply_.PushData(std::string(outPack.begin(), outPack.end()).c_str(),
                        outPack.size());
        cli->SendPacket(reply_);
        reply_.Clear();

        // // 3
        Protocol::EofPacket eof(1, 2);
        std::vector<uint8_t> eofPacket = eof.Pack();
        seq++;  // 254, 0, 0, 2, 0
        std::vector<uint8_t> outPackNew;
        outPackNew.push_back(eofPacket.size());
        outPackNew.push_back(0);
        outPackNew.push_back(0);
        outPackNew.push_back(seq);
        outPackNew.insert(outPackNew.end(), eofPacket.begin(), eofPacket.end());
        reply_.PushData(
            std::string(outPackNew.begin(), outPackNew.end()).c_str(),
            outPackNew.size());

        cli->SendPacket(reply_);
        reply_.Clear();

        // 4
        seq++;
        std::vector<std::string> reslist;
        reslist.push_back(res);
        reslist.push_back(res);
        Protocol::RowPacket rowPack(reslist);
        std::vector<uint8_t> rowPacket = rowPack.Pack();
        std::vector<uint8_t> outPack1;
        outPack1.push_back(rowPacket.size());
        outPack1.push_back(0);
        outPack1.push_back(0);
        outPack1.push_back(seq);
        outPack1.insert(outPack1.end(), rowPacket.begin(), rowPacket.end());
        reply_.PushData(std::string(outPack1.begin(), outPack1.end()).c_str(),
                        outPack1.size());
        cli->SendPacket(reply_);
        reply_.Clear();

        // 5
        seq++;
        Protocol::EofPacket eofBack(0, 2);
        std::vector<uint8_t> eofBackPacket = eofBack.Pack();
        std::vector<uint8_t> outPack2;
        outPack2.push_back(eofBackPacket.size());
        outPack2.push_back(0);
        outPack2.push_back(0);
        outPack2.push_back(seq);
        outPack2.insert(outPack2.end(), eofBackPacket.begin(),
                        eofBackPacket.end());
        reply_.PushData(std::string(outPack2.begin(), outPack2.end()).c_str(),
                        outPack2.size());
        cli->SendPacket(reply_);
        reply_.Clear();
        break;
      }
      case hsql::kStmtInsert: {
        uint64_t ret = ExecInsertStatement(
            (const hsql::InsertStatement*)result.getStatement(i), 0);
        Protocol::OkPacket okPack;
        std::vector<uint8_t> outPut = okPack.Pack(ret, 0, 2, 1);
        std::vector<uint8_t> res;
        res.push_back(outPut.size());
        res.push_back(0);
        res.push_back(0);
        res.push_back(1);
        res.insert(res.end(), outPut.begin(), outPut.end());
        reply_.PushData(std::string(res.begin(), res.end()).c_str(),
                        res.size());
        cli->SendPacket(reply_);
        reply_.Clear();
        break;
      }
      case hsql::kStmtDelete: {
        ExecDeleteStatement(
            (const hsql::DeleteStatement*)result.getStatement(i), 0);
        break;
      }
      case hsql::kStmtUpdate: {
        ExecUpdateStatement(
            (const hsql::UpdateStatement*)result.getStatement(i), 0);
        break;
      }
      default: {
        Protocol::OkPacket okPack;
        std::vector<uint8_t> outPut = okPack.Pack(0, 0, 2, 1);
        outPut[3] = pack[3] + 1;
        reply_.PushData(std::string(outPut.begin(), outPut.end()).c_str(),
                        outPut.size());
        cli->SendPacket(reply_);
        reply_.Clear();
      }
    }
  }
  return true;
}

Executor::Executor() {}

Executor::~Executor() {}

}  // namespace uhp_sql