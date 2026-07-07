# Write your MySQL query statement below
SELECT P.firstName, P.lastName, A.city, A.state FROM Person AS P LEFT JOIN Address AS A on P.personId = A.personId; 
