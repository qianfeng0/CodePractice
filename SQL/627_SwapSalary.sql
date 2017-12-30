/*
Given a table salary, such as the one below, that has m=male and f=female values. Swap all f and m values (i.e., change all f values to m and vice versa) with a single update query and no intermediate temp table.

For example:
| id | name | sex | salary |
|----|------|-----|--------|
| 1  | A    | m   | 2500   |
| 2  | B    | f   | 1500   |
| 3  | C    | m   | 5500   |
| 4  | D    | f   | 500    |
After running your query, the above salary table should have the following rows:
| id | name | sex | salary |
|----|------|-----|--------|
| 1  | A    | f   | 2500   |
| 2  | B    | m   | 1500   |
| 3  | C    | f   | 5500   |
| 4  | D    | m   | 500    |
*/

USE Leetcode;

CREATE TABLE IF NOT EXISTS salary
(
	id INT NOT NULL AUTO_INCREMENT,
    name CHAR(1) NOT NULL,
    sex CHAR(1) NOT NULL,
    salary INT NOT NULL,
    PRIMARY KEY(id)
);

INSERT INTO salary
(id, name, sex, salary)
VALUES
(1, 'A', 'm', 2500),
(2, 'B', 'f', 1500),
(3, 'C', 'm', 5500),
(4, 'D', 'f', 500);

SET SQL_SAFE_UPDATES = 0;

UPDATE salary
SET sex = (CASE sex WHEN 'f' THEN 'm' ELSE 'f' END);

SET SQL_SAFE_UPDATES = 1;

SELECT *
FROM salary;

DROP TABLE salary;
