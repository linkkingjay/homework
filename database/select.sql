-- 简单查询：
-- 查询全部学生的学号、姓名、性别和出身年月日。
-- SELECT s_no, sname, sbirthday FROM lqj_student;

-- 根据学号=“你的学号”查询对应元组的姓名和年龄。
-- SELECT sname, YEAR(GETDATE()) - YEAR(sbirthday) age FROM lqj_student WHERE s_no='5931';

-- 查询院系编号为‘510000’（计算机学院）的全部学生的学号、姓名、性别和出生年月日。
-- SELECT s_no, sname, sex, sbirthday FROM lqj_student WHERE dno='510000'; 

-- 查询“计算机科学与技术”专业（专业代码为‘00080605’）并且班级代码为‘0201’的学生的学号、姓名和出生日期。
-- SELECT s_no, sname, sbirthday FROM lqj_student WHERE spno='00080605' AND class_no='0201';

-- 查询在‘1990/01/01’以后出生的计算机学院（院系编号为‘510000’）学生的学号、姓名、性别和出身年月日。
-- SELECT s_no, sname, sex, sbirthday FROM lqj_student WHERE sbirthday>'1990-01-01' AND dno='510000';

-- 查询全部学生的学号、姓名、性别和出身日期结果按照出生日期的升序排列。
-- SELECT s_no, sname, sex, sbirthday FROM lqj_student ORDER BY sbirthday;



-- 连接查询：
-- 查询全部学生的学号、姓名、性别、所在院系名称和专业名称
-- SELECT s_no, sname, sex, dept_name, spname FROM lqj_student s, lqj_department d, lqj_speciality sp 
-- WHERE s.dno = d.dno AND s.spno = sp.spno;
-- 查询选修了课程1（上课编号）的学生的学号、姓名、专业名称和这门课的成绩
-- SELECT s.s_no, sname, spname, score FROM lqj_student s, lqj_student_course sc, lqj_speciality sp 
-- WHERE s.spno = sp.spno AND s.s_no = sc.s_no AND tcid=1;
-- 查询学生不及格的情况列出不及格学生的学号、姓名和不及格的课程名称。
-- SELECT s.s_no, sname, cname FROM lqj_student s, lqj_Course c, lqj_student_course sc, lqj_teacher_course tc
-- WHERE sc.score < 60 AND s.s_no = sc.s_no AND tc.tcid = sc.tcid AND tc.cno = c.cno;

-- 嵌套查询：
-- 查询没有选修了课程1的学生，列出学生的学号和姓名。
-- SELECT s_no, sname FROM lqj_student WHERE s_no NOT IN (SELECT s_no FROM lqj_student_course WHERE tcid = 1);
-- 查询每门课都是80分以上的学生的学号与姓名。
-- SELECT s_no, sname FROM lqj_student WHERE s_no IN (SELECT s_no FROM lqj_student_course GROUP BY s_no HAVING MIN(score) >= 80);
