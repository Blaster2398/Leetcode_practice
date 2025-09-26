# Write your MySQL query statement below
select w.id 
from weather w
join weather e
 on datediff(w.recordDate, e.recordDate) = 1 
where  w.Temperature > e.Temperature;;