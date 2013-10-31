DROP TABLE lqj_teacher_course;
DROP TABLE lqj_student_course;
DROP TABLE lqj_class;
DROP TABLE lqj_teacher;
DROP TABLE lqj_Course;
DROP TABLE lqj_student;
DROP TABLE lqj_speciality;
DROP TABLE lqj_department;

CREATE TABLE lqj_department
(
    dno  char(6)   PRIMARY KEY,
    dept_name  char(20)  not null,
    header     char(8)
);
CREATE TABLE lqj_speciality
(
    spno       char(8)   PRIMARY KEY,
    dno        char(6)   not null ,
    spname     char(20)  not null,
    FOREIGN KEY (dno) REFERENCES lqj_department(dno)
);
CREATE TABLE lqj_student(
    s_no	  char(8) PRIMARY KEY,
    sname	  char(8) not null,
    sex		  char(2),
    sbirthday smalldatetime,
    dno		  char(6),
    spno	  char(8),
    class_no  char(4),
    FOREIGN KEY (spno) REFERENCES lqj_speciality(spno),
    FOREIGN KEY (dno) REFERENCES lqj_department(dno)
);
CREATE TABLE lqj_Course
(
    cno       char(10)  PRIMARY KEY,
    cname      char(20)  not null,
    spno        char(8),
    ctno  tinyint,
    lecture  tinyint,
    experiment  tinyint,
    semester  tinyint,
    credit  tinyint,
    constraint fk_lqj_Course_spno  foreign key(spno)  REFERENCES lqj_speciality(spno)
);
CREATE TABLE lqj_student_course
(
    s_no       char(8) ,
    tcid       smallint ,
    score      tinyint , 
    constraint pk_lqj_student_course PRIMARY KEY (s_no,tcid),
    constraint fk_lqj_student_course_s_no foreign key(s_no) REFERENCES lqj_student(s_no) on delete cascade
);
CREATE TABLE lqj_teacher
(
    t_no       char(8) PRIMARY KEY,
    t_name       char(8) not null,
    t_sex       char(2) ,
    t_birthday       smalldatetime ,
    dno       char(6) ,
    tech_title       char(10) ,
    constraint fk_lqj_teacher_dno foreign key(dno) REFERENCES lqj_department(dno) 
);
CREATE TABLE lqj_teacher_course
(
    tcid       smallint PRIMARY KEY,
    t_no       char(8) ,
    spno       char(8) ,
    class_no       char(4) ,
    cno       char(10) not null ,
    semester       char(6) ,
    schoolyear       char(10) ,
    constraint fk_lqj_teacher_course_t_no foreign key(t_no) REFERENCES lqj_teacher(t_no), 
    constraint fk_lqj_teacher_course_spno foreign key(spno) REFERENCES lqj_speciality(spno), 
    constraint fk_lqj_teacher_course_cno foreign key(cno) REFERENCES lqj_Course(cno)
);
CREATE TABLE lqj_class
(
    spno       char(8) ,
    class_no   char(4) ,
    header     char(8) , 
    constraint pk_class PRIMARY KEY (spno,class_no),
    constraint fk_lqj_class_spno foreign key(spno) REFERENCES lqj_speciality(spno)
); 
