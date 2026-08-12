# Write your MySQL query statement below
select p1.product_id, 'store1' as store, p1.store1 as price from products as p1
where p1.store1 is not null
union
select product_id,'store2' as store,store2 as price from products as p2
where p2.store2 is not null
union
select product_id,'store3' as store,store3 as price from products as p3
where p3.store3 is not null