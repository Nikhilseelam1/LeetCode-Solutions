# Write your MySQL query statement below
select 
x1.d_name as Department,x1.name as Employee,x1.salary as Salary
from
(
select
x.d_name,
x.salary,
dense_rank() over(partition by x.departmentId order by x.salary desc) as rnk,
x.name
from
(
select 
e.id,e.name,e.salary,e.departmentId,d.name as d_name
from 
Employee e
join Department d
on e.departmentId = d.id 
) as x
) as x1
where x1.rnk=1