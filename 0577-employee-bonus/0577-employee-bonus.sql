# Write your MySQL query statement below
select name,bonus
from
(
select 
 e.empId,
 b.empId as bonus_empid,
 e.name,
 b.bonus
from 
Employee e 
left join
Bonus b
on 
e.empId = b.empId
) as x
where x.bonus<1000 or x.bonus is null;
