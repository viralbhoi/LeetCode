# Write your MySQL query statement below
SELECT
    d.name AS `Department`,
    e.name AS `Employee`,
    e.salary AS `Salary`
FROM Employee e INNER JOIN Department d ON d.id = e.departmentId
WHERE e.salary = (
    SELECT MAX(e2.salary) 
    FROM Employee e2
    WHERE e.departmentId = e2.departmentId 
)