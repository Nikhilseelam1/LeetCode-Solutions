# Write your MySQL query statement below
select x.class
from 
(select class,count(class) as c
from 
Courses
group by class) as x
where x.c >= 5