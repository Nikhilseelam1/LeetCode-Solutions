# Write your MySQL query statement below
select 
e.employee_id
from 
Employees e
where e.manager_id not in (select e1.employee_id from Employees as e1) 
and
e.salary<30000 
order by employee_id