# Write your MySQL query statement below
select 
round(sum(i1.tiv_2016),2) as tiv_2016
from 
Insurance i1
where (i1.lat,i1.lon) in
(
select 
lat,lon
from 
Insurance
group by lat,lon
having count(*)=1
)
and 
i1.tiv_2015 in
(
select
tiv_2015
from 
Insurance 
group by tiv_2015 
having count(tiv_2015)>1
)