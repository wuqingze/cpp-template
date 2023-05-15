show databases;
use test00;

CREATE TABLE test00.person (
    age INT,
    gender VARCHAR(10),
    name VARCHAR(50),
    phone VARCHAR(20),
    email VARCHAR(50),
    birth DATE
  );


-- 插入10条随机数据
INSERT INTO test00.person (age, gender, name, phone, email, birth)
SELECT
  FLOOR(RAND() * 100) AS age,
  CASE WHEN RAND() < 0.5 THEN 'Male' ELSE 'Female' END AS gender,
  CONCAT('Person', FLOOR(RAND() * 100)) AS name,
  CONCAT('1', FLOOR(RAND() * 100000000)) AS phone,
  CONCAT('person', FLOOR(RAND() * 100), '@example.com') AS email,
  DATE_ADD('1970-01-01', INTERVAL FLOOR(RAND() * 365*50) DAY) AS birth
FROM
  -- 生成10个随机数
  (SELECT 1 UNION SELECT 2 UNION SELECT 3 UNION SELECT 4 UNION SELECT 5
   UNION SELECT 6 UNION SELECT 7 UNION SELECT 8 UNION SELECT 9 UNION SELECT 10) AS numbers;
