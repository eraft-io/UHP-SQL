# prepare tables
./bin/benchyou --mysql-host=127.0.0.1 --mysql-user=root --mysql-password=test --mysql-port 12306 --oltp-tables-count=1 prepare

./bin/benchyou --mysql-host=127.0.0.1 --mysql-user=root --mysql-password=test --mysql-port 12306 --oltp-tables-count=1 --write-threads=1 --read-threads=0 --delete-threads=0 --update-threads=0 --max-time=6 random 

./bin/benchyou --mysql-host=127.0.0.1 --mysql-user=root --mysql-password=test --mysql-port 12306 --oltp-tables-count=1 --write-threads=0 --read-threads=1 --delete-threads=0 --update-threads=0 --max-time=6 random 

./bin/benchyou --mysql-host=127.0.0.1 --mysql-user=root --mysql-password=test --mysql-port 12306 --oltp-tables-count=1 --write-threads=0 --read-threads=0 --delete-threads=1 --update-threads=0 --max-time=6 random 

./bin/benchyou --mysql-host=127.0.0.1 --mysql-user=root --mysql-password=test --mysql-port 12306 --oltp-tables-count=1 --write-threads=0 --read-threads=0 --delete-threads=0 --update-threads=1 --max-time=6 random 
