SELECT 
    u.user_id as buyer_id ,
    u.join_date,
    sum(IF(o.order_date >= '2019-01-01' 
            AND o.order_date <= '2019-12-31', 1, 0)) AS orders_in_2019
FROM Users u
LEFT JOIN Orders o
    ON u.user_id = o.buyer_id
GROUP BY u.user_id, u.join_date;