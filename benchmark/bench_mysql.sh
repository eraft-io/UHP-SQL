#!/usr/bin/env bash

# prepare tables
./bin/benchyou --mysql-host=127.0.0.1 --mysql-user=root --mysql-password=123 --mysql-db=testdb --mysql-port 3306 --oltp-tables-count=1 prepare

# insert test
./bin/benchyou --mysql-host=127.0.0.1 --mysql-user=root --mysql-password=123 --mysql-db=testdb --mysql-port 3306 --oltp-tables-count=1 --write-threads=128 --read-threads=0 --delete-threads=0 --update-threads=0 --max-time=60  --ssh-host=iZ2ze5eib0jy8eahk1mzmpZ --ssh-password=work@good308 --ssh-port=22 --ssh-user=root random >  i_128_mysql.txt

./bin/benchyou --mysql-host=127.0.0.1 --mysql-user=root --mysql-password=123 --mysql-db=testdb --mysql-port 3306 --oltp-tables-count=1 --write-threads=10 --read-threads=0 --delete-threads=0 --update-threads=0 --max-time=60  --ssh-host=iZ2ze5eib0jy8eahk1mzmpZ --ssh-password=work@good308 --ssh-port=22 --ssh-user=root random >  i_10_mysql.txt

./bin/benchyou --mysql-host=127.0.0.1 --mysql-user=root --mysql-password=123 --mysql-db=testdb --mysql-port 3306 --oltp-tables-count=1 --write-threads=2 --read-threads=0 --delete-threads=0 --update-threads=0 --max-time=60  --ssh-host=iZ2ze5eib0jy8eahk1mzmpZ --ssh-password=work@good308 --ssh-port=22 --ssh-user=root random >  i_2_mysql.txt

./bin/benchyou --mysql-host=127.0.0.1 --mysql-user=root --mysql-password=123 --mysql-db=testdb --mysql-port 3306 --oltp-tables-count=1 --write-threads=32 --read-threads=0 --delete-threads=0 --update-threads=0 --max-time=60  --ssh-host=iZ2ze5eib0jy8eahk1mzmpZ --ssh-password=work@good308 --ssh-port=22 --ssh-user=root random >  i_32_mysql.txt


# select test
./bin/benchyou --mysql-host=127.0.0.1 --mysql-user=root --mysql-password=123 --mysql-db=testdb --mysql-port 3306 --oltp-tables-count=1 --write-threads=0 --read-threads=1 --delete-threads=0 --update-threads=0 --max-time=60  --ssh-host=iZ2ze5eib0jy8eahk1mzmpZ --ssh-password=work@good308 --ssh-port=22 --ssh-user=root random > s_1_mysql.txt

# delete test
./bin/benchyou --mysql-host=127.0.0.1 --mysql-user=root --mysql-password=123 --mysql-db=testdb --mysql-port 3306 --oltp-tables-count=1 --write-threads=0 --read-threads=0 --delete-threads=1 --update-threads=0 --max-time=60  --ssh-host=iZ2ze5eib0jy8eahk1mzmpZ --ssh-password=work@good308 --ssh-port=22 --ssh-user=root random > d_1_mysql.txt 

# update test
./bin/benchyou --mysql-host=127.0.0.1 --mysql-user=root --mysql-password=123 --mysql-db=testdb --mysql-port 3306 --oltp-tables-count=1 --write-threads=0 --read-threads=0 --delete-threads=0 --update-threads=1 --max-time=60  --ssh-host=iZ2ze5eib0jy8eahk1mzmpZ --ssh-password=work@good308 --ssh-port=22 --ssh-user=root random > u_1_mysql.txt 
