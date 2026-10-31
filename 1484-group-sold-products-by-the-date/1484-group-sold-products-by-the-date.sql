WITH unique_products AS (
    SELECT DISTINCT
        sell_date,
        product
    FROM Activities
)

SELECT
    sell_date,
    COUNT(*) AS num_sold,
    GROUP_CONCAT(
        product
        ORDER BY product ASC
        SEPARATOR ','
    ) AS products
FROM unique_products
GROUP BY sell_date
ORDER BY sell_date;