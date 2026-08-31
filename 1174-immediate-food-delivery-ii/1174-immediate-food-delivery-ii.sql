# Write your MySQL query statement below
select 
round((count(x2.order_date)/(select count(distinct customer_id) from Delivery))*100,2) as immediate_percentage 
from
(
select 
        x.order_date,
        x.customer_pref_delivery_date
    from Delivery x
    where x.order_date = (
        select min(x1.order_date)
        from Delivery x1
        where x1.customer_id = x.customer_id
    )
    and x.order_date = x.customer_pref_delivery_date 
) as x2
