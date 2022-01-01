FROM pmem/pmemkv:1.4-ubuntu-20.04

COPY install-libpmemobjcpp.sh install-libpmemobjcpp.sh
RUN ./install-libpmemobjcpp.sh DEB

RUN echo pass | sudo -S apt-get update && \
    echo pass | sudo -S apt-get upgrade && \
    echo pass | sudo -S apt-get install flex bison -y
