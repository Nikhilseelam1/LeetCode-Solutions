# Write your MySQL query statement below
select 
DATE_FORMAT(trans_date, '%Y-%m') AS month,
country,
count(state) as trans_count,
sum(amount) as trans_total_amount,
sum(case when state='approved' then 1
when state='declined' then 0
end) as approved_count,
sum(case when state='approved' then amount
when state='declined' then 0
end) as approved_total_amount 
from 
Transactions t
group by country,DATE_FORMAT(trans_date, '%Y-%m') 
