# Write your MySQL query statement below
select x.email as Email from
(select email,count(email) as c from Person p
group by email
having c>1) as x
