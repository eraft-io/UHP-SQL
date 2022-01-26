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
Class,
Score
) 
VALUES 
('Tom', 
'B', 
'98');

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
