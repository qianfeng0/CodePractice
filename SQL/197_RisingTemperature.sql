/*
Given a Weather table, write a SQL query to find all dates' Ids with higher temperature compared to its previous (yesterday's) dates.

+---------+------------+------------------+
| Id(INT) | Date(DATE) | Temperature(INT) |
+---------+------------+------------------+
|       1 | 2015-01-01 |               10 |
|       2 | 2015-01-02 |               25 |
|       3 | 2015-01-03 |               20 |
|       4 | 2015-01-04 |               30 |
+---------+------------+------------------+
For example, return the following Ids for the above Weather table:
+----+
| Id |
+----+
|  2 |
|  4 |
+----+
*/

USE Leetcode;

CREATE TABLE IF NOT EXISTS  Weather
(
	Id INT NOT NULL AUTO_INCREMENT,
    Date DATE NOT NULL,
    Temperature INT NOT NULL,
    PRIMARY KEY(Id)
);

DELETE
FROM Weather
WHERE Id < 10;

INSERT INTO Weather
(Id, Date, Temperature)
VALUES
(1, '2015-01-01', 10),
(2, '2015-01-02', 25),
(3, '2015-01-03', 20),
(4, '2015-01-04', 30);

/*
SELECT w1.Id
FROM Weather AS w1, Weather AS w2
WHERE TO_DAYS(w1.Date) = TO_DAYS(w2.Date) + 1 and w1.Temperature > w2.Temperature;
*/

SELECT w1.Id
FROM Weather w1 INNER JOIN Weather w2
ON TO_DAYS(w1.Date) = TO_DAYS(w2.Date) + 1 and w1.Temperature > w2.Temperature;

DROP TABLE Weather;