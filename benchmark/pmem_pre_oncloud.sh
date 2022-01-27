#!/usr/bin/env bash

apt-get install ndctl daxctl
ndctl create-namespace -f -e namespace0.0 --mode=devdax

ndctl create-namespace -f -e namespace0.0 --mode=fsdax
mkfs -t ext4 /dev/pmem0
mkdir /mnt/sdb
mount -o dax,noatime /dev/pmem0 /mnt/sdb
df -h