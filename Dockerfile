FROM pmem/pmemkv:1.4-ubuntu-20.04

COPY install-libpmemobjcpp.sh install-libpmemobjcpp.sh
RUN ./install-libpmemobjcpp.sh DEB

RUN echo pass | sudo -S apt-get update -y && \
    echo pass | sudo -S apt-get upgrade -y

RUN echo pass | sudo -S git clone https://github.com/redis/redis.git &&  cd redis &&  echo pass | sudo -S  git checkout 48e24d54b736b162617112ce27ec724b9290592e && echo pass | sudo -S make > /dev/null && echo pass | sudo -S  make install > /dev/null
