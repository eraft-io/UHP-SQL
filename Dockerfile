FROM pmem/pmemkv:1.4-ubuntu-20.04

COPY install-libpmemobjcpp.sh install-libpmemobjcpp.sh
RUN ./install-libpmemobjcpp.sh DEB

RUN echo pass | sudo -S apt-get update -y && \
    echo pass | sudo -S apt-get upgrade -y

COPY install-pmemkvredis.sh install-pmemkvredis.sh
RUN ./install-pmemkvredis.sh

COPY pmem_redis.toml pmem_redis.toml
