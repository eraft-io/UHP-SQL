#!/usr/bin/env bash

set -e

nohup ./home/user/pmemkv/build_/network/pmemkv_redisd /pmem_redis.toml &

sleep 2s
# run server
/UHP-SQL/build/server/uhpsqld
