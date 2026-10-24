# Write your MySQL query statement below
WITH aux_tab AS (
    SELECT reports_to, COUNT(reports_to) as reports_count , ROUND(AVG(age), 0) as average_age FROM Employees
    GROUP BY reports_to
)
SELECT e.employee_id, e.name, a.reports_count, a.average_age
FROM Employees e
JOIN aux_tab a
ON e.employee_id = a.reports_to
ORDER BY e.employee_id;