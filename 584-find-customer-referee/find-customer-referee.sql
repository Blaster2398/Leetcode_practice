# Write your MySQL query statement below
SELECT NAME
FROM Customer
WHERE referee_id is null or referee_id != 2;