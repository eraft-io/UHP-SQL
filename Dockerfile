FROM pmem/pmemkv:ubuntu-18.04

RUN set -e; echo pass | sudo -S apt update -qq && \
    echo pass | sudo -S apt install -y -qq libtbb-dev && \
    echo pass | sudo -S apt install golang -y

RUN echo pass | sudo -S git clone https://github.com/pmem/pmemkv /tmp/pmemkv_src &&  \
    cd /tmp/pmemkv_src &&  \
    echo pass | sudo -S git checkout f0c5c983c5c3264859fc317ce86a04c9bc080178 && \
    echo pass | sudo -S mkdir bin && \
    cd bin && \
    echo pass | sudo -S cmake .. && \
    echo pass | sudo -S make && \
    echo pass | sudo -S cp libpmemkv.so /usr/local/lib/ && \
    echo pass | sudo -S cp ../src/pmemkv.h /usr/local/include/libpmemkv.h \