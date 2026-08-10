# Write your MySQL query statement below
select 
x.product_name,sum(x.unit) as unit
from
(
select 
p.product_id,
p.product_name,
o.order_date,
o.unit
from 
Products p
join 
Orders o
on p.product_id = o.product_id
) as x
where order_date>='2020-02-01' and order_date<='2020-02-29'
group by x.product_id
having sum(x.unit)>=100

