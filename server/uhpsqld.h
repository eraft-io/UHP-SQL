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

#include "../network/server.h"

#define VERSION "1.0.0"
#define MOCK_PMEMKV_REDIS_IP "172.17.0.2"
#define MOCK_PMEMKV_REDIS_PORT 6379
#define DEMO_SERVER_ADDR "0.0.0.0:12306"

class Uhpsqld : public Server {
 public:
  Uhpsqld();
  ~Uhpsqld();

  // bool ParseArgs(int ac, char* av[]);

 private:
  std::shared_ptr<StreamSocket> _OnNewConnection(int fd, int tag) override;

  bool _Init() override;
  bool _RunLogic() override;
  bool _Recycle() override;

  unsigned short port_;
};
