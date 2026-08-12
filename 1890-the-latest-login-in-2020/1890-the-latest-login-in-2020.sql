# Write your MySQL query statement below
select 
l.user_id,max(l.time_stamp) as last_stamp
from
Logins l
where l.time_stamp>='2020-01-01 00:00:00' and  l.time_stamp<='2020-12-31 23:59:59'
group by user_id
