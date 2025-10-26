# Write your MySQL query statement below
SELECT 
    user_id AS `buyer_id`,
    join_date,
    (
        SELECT COUNT(order_id) FROM Orders
        WHERE buyer_id = user_id 
            AND order_date >= "2019-01-01" 
            AND order_date <= "2019-12-31"
    ) AS `orders_in_2019`
FROM Users