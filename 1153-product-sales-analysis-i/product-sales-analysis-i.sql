# Write your MySQL query statement below
select p.product_name, s.year, s.price 
from sales s 
natural left join product p;