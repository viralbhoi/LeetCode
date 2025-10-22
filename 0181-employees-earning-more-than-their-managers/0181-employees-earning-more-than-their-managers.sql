# Write your MySQL query statement below
SELECT e.name as `Employee`
FROM Employee e INNER JOIN Employee d
ON e.managerId = d.id
WHERE e.salary > d.salary