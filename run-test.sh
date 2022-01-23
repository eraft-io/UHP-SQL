#!/usr/bin/env bash

set -e

# mock pmemkv redis
nohup redis-server &

# run server
# /UHP-SQL/build/server/uhpsqld
/bin/bash