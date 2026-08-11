# Write your MySQL query statement below
select name,sum(x.amount) as balance
from
(select 
u.account,t.amount,u.name
from 
Users u 
join 
Transactions t
on u.account = t.account) as x
group by x.account
having sum(x.amount)>10000