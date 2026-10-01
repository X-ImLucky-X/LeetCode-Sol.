# Write your MySQL query statement below
SELECT a.student_id,a.student_name,b.subject_name,COUNT(c.student_id) AS attended_exams
FROM Students a
CROSS JOIN Subjects b     #makes every possible combination
LEFT JOIN Examinations c
ON c.student_id=a.student_id
AND c.subject_name=b.subject_name
GROUP BY a.student_id,a.student_name,b.subject_name
ORDER BY a.student_id,a.student_name,b.subject_name