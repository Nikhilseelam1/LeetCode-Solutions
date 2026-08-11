# Write your MySQL query statement 
select x.employee_id,
x.name,
count(reports_to) as reports_count,
round(avg(x.age)) as average_age
from
(
select 
e1.name,
e2.reports_to,
e1.employee_id,
e2.age
from
Employees e1
join Employees e2
on e1.employee_id = e2.reports_to) as x
group by x.reports_to
order by x.employee_id