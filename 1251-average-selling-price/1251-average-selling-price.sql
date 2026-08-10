# Write your MySQL query statement below

select 
x.product_id,
case when round(sum(x.units * x.price)/sum(units),2) is null then 0
else round(sum(x.units * x.price)/sum(units),2)
end as average_price
from
(
SELECT 
    p.product_id,
    p.price,
    u.units
FROM Prices p
LEFT JOIN UnitsSold u
    ON p.product_id = u.product_id
    AND u.purchase_date >= p.start_date
    AND u.purchase_date <= p.end_date
) as x
group by x.product_id
