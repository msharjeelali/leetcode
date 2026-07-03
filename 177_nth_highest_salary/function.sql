CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
    DECLARE var INT;
    SET var = N - 1;
  RETURN (
      # Write your MySQL query statement below.
      SELECT DISTINCT salary 
      FROM EMPLOYEE 
      ORDER BY salary DESC 
      LIMIT 1 OFFSET var
  );
END
