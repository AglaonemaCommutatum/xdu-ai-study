
CREATE DATABASE my_student_db;  

USE my_student_db;  

CREATE TABLE student (  
    id INT NOT NULL AUTO_INCREMENT,  
    name VARCHAR(50) NOT NULL,  
    age INT,  
    PRIMARY KEY (id)
);  
  
DESCRIBE student;  
  
SELECT   
    TABLE_NAME,   
    INDEX_NAME,   
    COLUMN_NAME,   
    SEQ_IN_INDEX,   
    CARDINALITY,   
    INDEX_TYPE,     
    NULLABLE   
FROM   
    information_schema.STATISTICS   
WHERE   
    TABLE_SCHEMA = 'my_student_db' 
    AND TABLE_NAME = 'student';  
    
    
INSERT INTO student (id, name, age) VALUES (1, 'Charlie', 21); 
INSERT INTO student (id, name, age) VALUES (2, 'Alice', 20);  
INSERT INTO student (id, name, age) VALUES (3, 'Bob', 22);  

-- 尝试插入一个具有相同id的数据
-- INSERT INTO student (id, name, age) VALUES (3, 'Dode', 22);  
