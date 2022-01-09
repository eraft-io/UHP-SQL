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

#include <stdlib.h>

#include <string>

// include the sql parser
#include "../parser/sql_parser.h"

// contains printing utilities
#include "../parser/sqlhelper.h"

// contains hiredis
#include "../executor/executor.h"
#include "../network/client.h"
#include "../network/server.h"
#include "../network/socket.h"
#include "../third_party/libredis/hiredis.h"
#include "uhpsqld.h"

Uhpsqld::Uhpsqld() : port_(0) {}

Uhpsqld::~Uhpsqld() {}

std::shared_ptr<StreamSocket> Uhpsqld::_OnNewConnection(int connfd, int tag) {
  SocketAddr peer;
  Socket::GetPeerAddr(connfd, peer);

  auto cli(std::make_shared<Client>());
  if (!cli->Init(connfd, peer)) cli.reset();
  return cli;
}

bool Uhpsqld::_Init() {
  SocketAddr addr(DEMO_SERVER_ADDR);
  uhp_sql::Executor::Init(MOCK_PMEMKV_REDIS_IP, MOCK_PMEMKV_REDIS_PORT);

  if (!Server::TCPBind(addr, 1)) {
    return false;
  }

  return true;
}

bool Uhpsqld::_RunLogic() { return Server::_RunLogic(); }

bool Uhpsqld::_Recycle() {}

int main(int argc, char *argv[]) {
  Uhpsqld svr;

  svr.MainLoop(false);

  return 0;
}
