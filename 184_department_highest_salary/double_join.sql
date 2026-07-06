# Write your MySQL query statement below
SELECT D.name AS Department , E.name AS Employee, E.salary AS Salary FROM Employee AS E JOIN Department AS D on E.DepartmentId = D.id JOIN (SELECT departmentId, MAX(salary) AS salary FROM Employee GROUP BY departmentId) as M ON E.departmentId = M.departmentId AND E.salary = M.salary;
