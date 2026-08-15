# Write your MySQL query statement below
select 
x.customer_id
from
(select
customer_id,count( distinct product_key) as c
 from
Customer 
group by customer_id) as x
where x.c = (select count(p.product_key) from Product p)