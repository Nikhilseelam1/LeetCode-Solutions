# Write your MySQL query statement below
select 
x.contest_id,round((count(x.contest_id)/(select count(user_id) from Users))*100,2) as percentage
from
(
select 
u.user_id,u.user_name,
r.contest_id
from 
Users u
join 
Register r
on u.user_id = r.user_id
) as x
group by x.contest_id
order by percentage desc,x.contest_id asc