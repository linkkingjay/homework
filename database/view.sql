-- CREATE VIEW ies_student_view AS SELECT s.s_no, s.sname, s.sex, s.sbirthday, sp.spname 
-- FROM lqj_student s, lqj_speciality sp, lqj_department d WHERE s.dno=d.dno AND s.spno=sp.spno AND d.dept_name='计算机学院';

-- CREATE VIEW ies_courseStudent_view AS SELECT s.s_no, s.sname, sp.spname, sc.score FROM
-- lqj_student s, lqj_speciality sp, lqj_student_course sc WHERE s.spno=sp.spno AND s.s_no=sc.s_no AND sc.tcid=1;

-- CREATE VIEW ies_failedStudent_view AS SELECT s.s_no, s.sname, tc.cno FROM
-- lqj_student s, lqj_teacher_course tc, lqj_student_course sc WHERE s.s_no=sc.s_no AND sc.score<60 AND tc.tcid=sc.tcid;

-- ALTER VIEW ies_student_view AS SELECT s.s_no, s.sname, s.sex, s.sbirthday, d.dept_name, sp.spname FROM
-- lqj_student s, lqj_department d, lqj_speciality sp WHERE s.dno=d.dno AND sp.spno=s.spno;

-- DROP VIEW ies_student_view;
