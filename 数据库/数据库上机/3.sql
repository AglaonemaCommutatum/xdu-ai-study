DROP DATABASE stusys;
SET SQL_SAFE_UPDATES = 0;
CREATE DATABASE stusys DEFAULT CHARACTER SET GBK;
USE stusys;
CREATE TABLE student (
    sno CHAR(6) NOT NULL,
    sname CHAR(8) NOT NULL,
    ssex CHAR(1),
    sbirth char(4),
    zno CHAR(4),
    sclass CHAR(6),
    tel CHAR(11)
);
DESC student;
INSERT student(sno,sname,ssex,sbirth,zno,sclass)
VALUES ('152010','李四','男','0317','1001','人工智能01'),
('152011','赵四','男','0301','1001','人工智能02'),
('152012','张三','男','0917','1003','人工智能12'),
('152013','王雅','女','0526','1502','人工智能02');
SELECT * from student;
UPDATE student SET sclass='人工智能05',zno='1513' where sno='152011';
SELECT * from student;
DELETE FROM student where sname='张三';
SELECT * from student;


USE stusys;
CREATE TABLE sc
(sno char(6) NOT NULL,
sname char(8) NOT NULL,
chigrade char(6),
mathgrade char(6),
enggrade char(6),
sclass char(6),
zno char(4)
);
DESC sc;
INSERT sc(sno,sname,chigrade,mathgrade,enggrade,sclass,zno)
VALUES ('152010','李四','79','81','80','人工智能01','1001'),
('152011','赵四','70','85','74','人工智能02','1001'),
('152012','张三','90','97','93','人工智能12','1003'),
('152013','王雅','74','86','83','人工智能02','1502');
SELECT * from sc;
SELECT sno,chigrade as '学号','语文成绩' from sc where chigrade between 75 and 85;
SELECT * from sc where sclass='人工智能02' and sname like'王%';
SELECT max(chigrade),max(mathgrade),max(enggrade) from sc;
SELECT * 
FROM sc natural join student 
limit 4;

