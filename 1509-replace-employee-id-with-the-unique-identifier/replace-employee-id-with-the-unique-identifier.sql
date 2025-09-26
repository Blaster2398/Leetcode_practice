# Write your MySQL query statement below
SELECT En.unique_id, E.name
FROM Employees E
LEFT JOIN EmployeeUNI En
ON E.id = En.id;



