/*
Write a SQL query to delete all duplicate email entries in a table named Person, keeping only unique emails based on its smallest Id.

+----+------------------+
| Id | Email            |
+----+------------------+
| 1  | john@example.com |
| 2  | bob@example.com  |
| 3  | john@example.com |
+----+------------------+
Id is the primary key column for this table.
For example, after running your query, the above Person table should have the following rows:

+----+------------------+
| Id | Email            |
+----+------------------+
| 1  | john@example.com |
| 2  | bob@example.com  |
+----+------------------+
*/

USE Leetcode;

CREATE TABLE IF NOT EXISTS Person
(
	Id INT NOT NULL auto_increment,
    Email char(50) NOT NULL,
    primary key(Id)
);

DELETE FROM Person
where Id < 10;

INSERT INTO Person
(Id, Email)
VALUES
(1, 'john@example.com'),
(2, 'bob@example.com'),
(3, 'john@example.com');


SET SQL_SAFE_UPDATES = 0;

DELETE FROM Person
WHERE Id NOT IN
(
SELECT minId
FROM
	(
	SELECT min(Id) AS minId
	FROM Person
	GROUP BY Email
	) AS T
);
/*
DELETE p1
FROM Person AS p1, Person AS p2
WHERE p1.Email = p2.Email and p1.Id > p2.Id;
*/
SET SQL_SAFE_UPDATES = 1;


SELECT *
FROM Person;

DROP TABLE Person;