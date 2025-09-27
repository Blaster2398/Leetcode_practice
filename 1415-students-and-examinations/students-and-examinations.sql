SELECT s.student_id, 
       s.student_name, 
       sub.subject_name, 
       COUNT(e.subject_name) AS attended_exams
FROM students s
JOIN subjects sub 
LEFT JOIN examinations e ON s.student_id = e.student_id and e.subject_name = sub.subject_name
GROUP BY s.student_id, s.student_name, sub.subject_name
order by s.student_id;
