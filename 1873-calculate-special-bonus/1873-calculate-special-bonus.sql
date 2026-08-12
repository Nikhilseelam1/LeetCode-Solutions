# Write your MySQL query statement below
select 
e.employee_id ,
(case when e.employee_id % 2 = 1 and left(e.name,1) != 'M' then e.salary
else 0 
end) as bonus
from 
Employees e
order by employee_id