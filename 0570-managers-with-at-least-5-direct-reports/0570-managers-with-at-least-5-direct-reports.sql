# Write your MySQL query statement below
-- SELECT a.name
-- FROM Employee a
-- JOIN(
--     SELECT managerId,COUNT(*) AS directReports
--     FROM Employee
--     GROUP BY managerId
--     HAVING directReports>=5
-- ) b
-- ON a.id=b.managerId
#1) a->default table
#2) b->secondary table
#3) finding a=b where count(b.managerid)>=5 

SELECT a.name 
FROM Employee a 
JOIN Employee b ON a.id = b.managerId 
GROUP BY b.managerId 
HAVING COUNT(*) >= 5