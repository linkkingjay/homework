DELETE FROM lqj_teacher_course;
DELETE FROM lqj_student_course;
DELETE FROM lqj_class;
DELETE FROM lqj_teacher;
DELETE FROM lqj_Course;
DELETE FROM lqj_student;
DELETE FROM lqj_speciality;
DELETE FROM lqj_department;

INSERT INTO lqj_department (dno, dept_name, header) VALUES ('510000', '计算机学院', '吴伟民');
INSERT INTO lqj_department (dno, dept_name, header) VALUES ('510002', '自动化学院', '吴伟民');
INSERT INTO lqj_department (dno, dept_name, header) VALUES ('510003', '数学学院', '吴伟民');
INSERT INTO lqj_department (dno, dept_name, header) VALUES ('510004', '外国语学院', '吴伟民');
INSERT INTO lqj_department (dno, dept_name, header) VALUES ('510005', '物理学院', '吴伟民');

INSERT INTO lqj_speciality (spno, dno, spname) VALUES ('00080605', '510000', '计算机科学与技术');
INSERT INTO lqj_speciality (spno, dno, spname) VALUES ('00080601', '510000', '软件工程');
INSERT INTO lqj_speciality (spno, dno, spname) VALUES ('00080602', '510000', '网络工程');
INSERT INTO lqj_speciality (spno, dno, spname) VALUES ('00080603', '510004', '日语');
INSERT INTO lqj_speciality (spno, dno, spname) VALUES ('00080604', '510004', '英语');

INSERT INTO lqj_class (spno, class_no, header) VALUES ('00080605', '0201', '谢光强');
INSERT INTO lqj_class (spno, class_no, header) VALUES ('00080605', '0202', '冯永晋');
INSERT INTO lqj_class (spno, class_no, header) VALUES ('00080605', '0203', '李杨');
INSERT INTO lqj_class (spno, class_no, header) VALUES ('00080605', '0204', '陈云华');
INSERT INTO lqj_class (spno, class_no, header) VALUES ('00080605', '0205', '郝志峰');

INSERT INTO lqj_Course 
VALUES ('1', 'C', '00080605', 12, 64, 8, 1, 4);
INSERT INTO lqj_Course 
VALUES ('2', 'C++', '00080605', 12, 64, 8, 1, 4);
INSERT INTO lqj_Course 
VALUES ('3', 'Python', '00080605', 12, 64, 8, 1, 4);
INSERT INTO lqj_Course 
VALUES ('4', 'Ruby', '00080605', 12, 64, 8, 1, 4);
INSERT INTO lqj_Course 
VALUES ('5', 'Lisp', '00080605', 12, 64, 8, 1, 4);

INSERT INTO lqj_student  
VALUES ('5931', 'Link_s1', '男', '1900-01-01', '510000', '00080605', '0201');
INSERT INTO lqj_student  
VALUES ('5932', 'Link_s2', '男', '1999-01-01', '510000', '00080605', '0202');
INSERT INTO lqj_student  
VALUES ('5933', 'Link_s3', '男', '1900-01-01', '510000', '00080605', '0203');
INSERT INTO lqj_student  
VALUES ('5934', 'Link_s4', '男', '1900-01-01', '510000', '00080605', '0204');
INSERT INTO lqj_student  
VALUES ('5935', 'Link_s5', '男', '1900-01-01', '510000', '00080605', '0205');

INSERT INTO lqj_student_course  VALUES ('5931', 1, 100);
INSERT INTO lqj_student_course  VALUES ('5932', 2, 99);
INSERT INTO lqj_student_course  VALUES ('5933', 3, 98);
INSERT INTO lqj_student_course  VALUES ('5934', 5, 97);
INSERT INTO lqj_student_course  VALUES ('5935', 4, 96);

INSERT INTO lqj_teacher 
VALUES ('1', '图灵', '男', '1900-01-01', '510000', 'master');
INSERT INTO lqj_teacher 
VALUES ('2', '冯诺依曼', '男', '1923-01-01', '510000', 'master');
INSERT INTO lqj_teacher 
VALUES ('3', '麦卡锡', '男', '1934-01-01', '510000', 'master');
INSERT INTO lqj_teacher 
VALUES ('4', '高德纳', '男', '1956-01-01', '510000', 'master');
INSERT INTO lqj_teacher 
VALUES ('5', '克尼汗', '男', '1955-01-01', '510000', 'master');

INSERT INTO lqj_teacher_course 
VALUES (1, '1', '00080605', '0201', '1', '1', '1');
INSERT INTO lqj_teacher_course 
VALUES (2, '2', '00080605', '0202', '2', '2', '2');
INSERT INTO lqj_teacher_course 
VALUES (3, '3', '00080605', '0203', '3', '3', '3');
INSERT INTO lqj_teacher_course 
VALUES (4, '4', '00080605', '0204', '4', '4', '4');
INSERT INTO lqj_teacher_course 
VALUES (5, '5', '00080605', '0205', '5', '5', '5');
