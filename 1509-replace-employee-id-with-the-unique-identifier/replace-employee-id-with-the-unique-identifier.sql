# Write your MySQL query statement below
-- select EmployeeUNI.unique_id, Employees.name
-- from Employees 
-- natural left join employeeUNI;

select eu.unique_id,e.name
from Employees e left join EmployeeUNI eu on e.id = eu.id;