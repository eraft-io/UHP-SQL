
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
#include "../third_party/hiredis/hiredis.h"
#include "uhpsqld.h"

Uhpsqld::Uhpsqld() : port_(0) {}

Uhpsqld::~Uhpsqld() {}

std::shared_ptr<StreamSocket> Uhpsqld::_OnNewConnection(int connfd, int tag) {
  // new connection comming
  SocketAddr peer;
  Socket::GetPeerAddr(connfd, peer);

  auto cli(std::make_shared<Client>());
  if (!cli->Init(connfd, peer)) cli.reset();
  return cli;
}

bool Uhpsqld::_Init() {
  SocketAddr addr("0.0.0.0:12306");
  uhp_sql::Executor::Init("172.17.0.2", 6379);

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