# Write your MySQL query statement below
SELECT max(salary) as SecondHighestSalary 
FROM (
    SELECT
        salary,
        DENSE_RANK() OVER(ORDER BY salary DESC) AS rnk
    FROM Employee
) t
WHERE rnk = 2;
