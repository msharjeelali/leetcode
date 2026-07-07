# Write your MySQL query statement below
SELECT A.name AS Employee FROM Employee AS A JOIN Employee AS B ON A.managerId = B.id WHERE A.salary > B.salary; 
