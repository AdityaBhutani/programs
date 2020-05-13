-- https://leetcode.com/problems/big-countries/
CREATE TABLE World (name VARCHAR(255), continent VARCHAR(255), area int, population int);

INSERT INTO World (name, continent, area, population)
VALUES ("Afghanistan", "Asia", 652230, 25500100);
INSERT INTO World (name, continent, area, population)
VALUES ("Albania", "Europe", 28748, 2831741);
INSERT INTO World (name, continent, area, population)
VALUES ("Algeria", "Africa", 2381741, 37100000);
INSERT INTO World (name, continent, area, population)
VALUES ("Andorra", "Europe", 468, 78115);
INSERT INTO World (name, continent, area, population)
VALUES ("Angola", "Africa", 1246700, 20609294);

SELECT name, population, area FROM World WHERE population > 25000000 OR area > 3000000;