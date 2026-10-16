# Write your MySQL query statement below
SELECT DISTINCT v1.author_id as id FROM Views v1
WHERE v1.author_id = v1.viewer_id
ORDER BY v1.author_id;
