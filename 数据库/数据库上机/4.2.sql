CREATE DATABASE my_student;  
USE my_student;  
CREATE TABLE students (  
    id INT NOT NULL AUTO_INCREMENT,  
    name VARCHAR(50) NOT NULL,  
    age INT,  
    PRIMARY KEY (id)  
);
INSERT INTO students (name, age) VALUES ('Alice', 20);  
INSERT INTO students (name, age) VALUES ('Bob', 22);  
INSERT INTO students (name, age) VALUES ('Charlie', 21);

-- 创建视图alexview，假设这个视图只显示年龄大于20的学生
CREATE VIEW alexview AS  
SELECT id, name, age FROM students WHERE age > 20;
SELECT * FROM alexview;
DROP VIEW IF EXISTS alexview;