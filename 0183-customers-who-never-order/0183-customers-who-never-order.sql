# Write your MySQL query statement below
select name as Customers
from Customers c1
where c1.id not in
(select c.id from
Customers c join 
Orders o
on c.id=o.customerId)