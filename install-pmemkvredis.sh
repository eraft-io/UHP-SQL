#!/usr/bin/env bash

cd ${HOME}
git clone https://github.com/eraft-io/pmemkv.git
cd pmemkv
mkdir build_
cd build_
cmake ..
make  -j$(nproc)
