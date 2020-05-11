-- https://leetcode.com/problems/combine-two-tables/

-- "SQL - two tables are needed to be combined to find the city and state (which reside 
-- in Address Table), this is acheived by Person Table Left Outer Joining on Address Table 
-- which receives all the persons with addresses, even when the corresponding entry doesnt 
-- exist in Address table"


CREATE TABLE Person (PersonId int, FirstName VARCHAR(255), LastName VARCHAR(255));
CREATE TABLE Address (AddressId int, PersonId int, City VARCHAR(255), State VARCHAR(255));

INSERT INTO Person (PersonId, FirstName, LastName)
VALUES (1, 'P1F', 'P1L');
INSERT INTO Person (PersonId, FirstName, LastName)
VALUES (2, 'P2F', 'P2L');
INSERT INTO Person (PersonId, FirstName, LastName)
VALUES (3, 'P3F', 'P3L');
INSERT INTO Address (AddressId, PersonId, City, State)
VALUES (1, 1, 'C1', 'S1');

SELECT Person.FirstName, Person.LastName, Address.City, Address.State from 
Person LEFT OUTER JOIN Address ON
Person.PersonId = Address.PersonId;