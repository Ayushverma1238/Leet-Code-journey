# Write your MySQL query statement below

WITH unionTable AS (
    SELECT requester_id as id FROM RequestAccepted
    UNION ALL
    SELECT accepter_id as id FROM RequestAccepted
)
SELECT id, COUNT(*) as num FROM unionTable
GROUP BY id
ORDER BY COUNT(*) DESC
LIMIT 1;