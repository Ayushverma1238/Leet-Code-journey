# Write your MySQL query statement below
WITH rankTable AS (
    SELECT *,
        DENSE_RANK() OVER (PARTITION BY departmentId ORDER BY salary DESC)
        as salary_rank
    FROM Employee
) 
SELECT d.name as Department, e.name as Employee, salary as Salary FROM rankTable e
JOIN Department d
ON e.departmentId = d.id
WHERE e.salary_rank <= 3;