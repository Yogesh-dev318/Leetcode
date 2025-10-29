SELECT
    Students.student_id,
    Students.student_name,
    Subjects.subject_name,
    count(Examinations.subject_name) as attended_exams
FROM Students
JOIN Subjects
LEFT JOIN Examinations
ON Students.student_id = Examinations.student_id
AND Subjects.subject_name = Examinations.subject_name
group by Students.student_id, Subjects.subject_name
order by student_id ASC