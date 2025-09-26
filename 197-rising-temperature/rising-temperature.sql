# Write your MySQL query statement below
select w.id 
from weather w
join weather e
where datediff(w.recordDate, e.recordDate) = 1 And w.Temperature > e.Temperature;;