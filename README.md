
# UHP-SQL
UHP-SQL 是一个基于 [英特尔® 傲腾™ 持久内存 ](https://www.intel.cn/content/www/cn/zh/architecture-and-technology/optane-dc-persistent-memory.html) 设计的新型分布式关系型数据库系统。

### 架构

![UHP-SQL-v0.1.png](https://tva1.sinaimg.cn/large/006n3WWAly1gy0tvo3215j30qr0lydj1.jpg)

### 特性

#### 超高性能
持久化内存在性能上有天然的优势，使用 UHP-SQL 可以加速你的应用。在保证数据持久化的同时，获得超高性能的在线读写，以及查询分析能力。

#### 可扩展
UHP-SQL 使用 eraft 协议实现了数据库横向扩展的能力，并基于云原生平台开发实现，可以实现一键启动云上持久化内存数据库实例，5分钟启动，并提供了 Web 控制端，快速上手使用。

#### 支持 SQL
UHP-SQL 兼容 MySQL 协议标准，你可以轻松的使用 mysql 客户端连接上 UHP-SQL 实例，可以低成本将应用从老的 MySQL 迁移过来。

### 快速上手

目前 UHP-SQL 发布了 Demo v0.1 版本，可以在装有 docker 环境的机器上运行。

#### 1.生成镜像

```
git clone https://github.com/eraft-io/UHP-SQL.git; cd UHP-SQL
make image
```

#### 2.运行 UHP-SQL 实例
```
make build-dev
make run
```

#### 3.本地连接
注意：mysql 版本 <= 5.1.70

```
mysql --host 127.0.0.1 --port 12306 -u root
```

#### 4.读写测试
```
INSERT INTO test(id, comment) VALUES (666, 'hello UHP-SQL!');

SELECT * FROM test where id = '666';
```
运行结果

```
+---------------------+
| ALL                 |
+---------------------+
| 666,hello UHP-SQL!, |
+---------------------+
1 row in set (0.01 sec)
```
