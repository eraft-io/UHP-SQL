CREATE TABLE classtab 
( 
Name VARCHAR(100), 
Class VARCHAR(100), 
Score INT, 
PRIMARY KEY(Name)
);

INSERT INTO classtab 
(
Name, 
Class
) 
VALUES 
('Tom', 
'B');

INSERT INTO classtab 
(
Name, 
Class,
Score
) 
VALUES 
('Tom2', 
'B', 
'93');

INSERT INTO classtab 
(
Name, 
Class,
Score
) 
VALUES 
('Tom22', 
'B', 
'93');

INSERT INTO classtab 
(
Name, 
Class,
Score
) 
VALUES 
('Tom6', 
'B', 
'90');

SELECT * from classtab WHERE Name = 'Tom';

UPDATE classtab  SET Score='78' WHERE Name='Tom';

SELECT * from classtab WHERE Name = 'Tom';

DELETE FROM classtab WHERE Name='Tom';

SELECT * from classtab WHERE Name = 'Tom';

SELECT * from classtab WHERE Name > 'Tom' limit 10;

INSERT INTO classtab 
(
Name, 
Class,
Score
) 
VALUES 
('Tom886', 
'A', 
'90');

SELECT * from classtab WHERE Name LIKE 'Tom%' limit 10;

create table benchyou2 (
							id int not null,
							k int not null,
							c varchar(120) not null,
							pad varchar(60) not null,
							primary key (id)
							);

./bin/benchyou --mysql-host=127.0.0.1 --mysql-user=root --mysql-password=test --mysql-port 12306 --oltp-tables-count=64 prepare

