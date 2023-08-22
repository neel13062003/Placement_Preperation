-- SQL: TCL,DCL,DML,DQL

create table Dept(
    dept_id NUMBER PRIMARY KEY,
    dept_name VARCHAR(30),
    location VARCHAR(100),
    UNIQUE(dept_name)        
);

create table Emp(
    emp_id NUMBER PRIMARY KEY,
    emp_name VARCHAR(30) NOT NULL,
    dept_id NUMBER REFERENCES Dept(dept_id),
    job VARCHAR(30),
    salary NUMBER CHECK(Salary>=5000),
    mgr varchar2(30),
    comm NUMBER Default 100,
    email VARCHAR(30),
    phone VARCHAR(13),
    UNIQUE (email,phone) 
);

INSERT INTO Dept Values(1, 'CE', 'Nadiad');
Insert Into Dept(dept_id,dept_name,location) Values (2,'IT','Ahemdabad');
INSERT INTO Dept(dept_id, dept_name) Values(3, 'EC');

-- Diff In Delete,Drop,Truncate  -> Delete(rollback),Truncate(We not specify condition in where all records delete) same - Drop delete whole schema of table
DELETE FROM Emp Where emp_id = 4;
DELETE From Emp;

DESC Dept;

Drop Table Emp;

UPDATE Emp SET dept_id = 2 Where emp_id = 3;
UPDATE Dept SET dept_name = 'AI' WHERE location = 'Bhvanagar';


dept_id NUMBER REFERENCES Dept(dept_id) ON DELETE SET NULL ON UPDATE SET NULL
-DELETE FROM Dept WHERE dept_id = 5;
-UPDATE Dept SET dept_id = 7 WHERE dept_id = 6; 

dept_id NUMBER DEFAULT 1 REFERENCES Dept(dept_id) ON DELETE SET DEFAULT ON UPDATE SET DEFAULT
-DELETE FROM Dept WHERE dept_id = 2;
-UPDATE Dept SET dept_id = 8 WHERE dept_id = 3


CREATE TABLE Emp(emp_id NUMBER, emp_name varchar2(10) UNIQUE, salary NUMBER CHECK(Salary >=5000), phone varchar2(13), pincode varchar2(6));
• ALTER TABLE Emp ADD PRIMARY KEY(emp_id);
• ALTER TABLE Emp DROP UNIQUE(emp_name);
• ALTER TABLE Emp MODIFY CHECK(salary >= 10000);
• ALTER TABLE Emp ADD(address varchar2(30), dob date);
• ALTER TABLE Emp MODIFY(phone varchar2(20), emp_name varchar2(30));
• ALTER TABLE Emp DROP(pincode, address);
• ALTER TABLE Emp RENAME COLUMN phone TO mobile;
• ALTER TABLE Emp RENAME to Employee; or RENAME Emp to Employee;


SELECT emp_name FROM Emp WHERE dept = 1;
SELECT emp_id, emp_name FROM Emp, Dept WHERE dept = dept_id AND dept_name = 'IT';
SELECT job FROM Emp;
SELECT DISTINCT job FROM Emp;

-- Alias If Not Use then use Whole Table Name
SELECT E.Emp_name AS "Employee_name",
    D.Dept_name AS "Department_name"
    FROM Emp E, Dept D
    WHERE E.dept_id = D.Dept_id;


SELECT Emp_name, Sal*1.1 FROM Emp;
SELECT FNAME || LNAME AS "FULL_NAME" FROM Emp;
CREATE TABLE Salary AS (SELECT emp_id, sal from Emp WHERE ...);


SELECT * FROM Student WHERE name LIKE 'R%';
SELECT name FROM Student WHERE rank LIKE '_ _ _ _';
SELECT name FROM Student WHERE marks LIKE '90\%' escape '\' AND email LIKE 'abc\_%@%.%' escape '\';
SELECT * FROM Student WHERE name NOT LIKE 'R%';


SELECT A,B,C FROM R ORDER BY A,B,C;
SELECT A,B,C FROM R ORDER BY A DESC,B,C

SELECT d.Dname, e.LNAME, e.FNAME, p.Pname
 FROM Employee e, WORKS_ON w, Project p, Department d
 WHERE e.Dno = d.Dnumber AND e.SSN = w.essn AND p.Pnumber = w.Pno
 ORDER BY d.Dname, e.LNAME, e.FNAME;

SELECT Fnames FROM Employee WHERE Dno IN(2,3,4,5); 
SELECT Fname, Address FROM Employee WHERE Dno IN ( SELECT Dnumber FROM Dept_Locations WHERE Dlocation = 'Newyork');
DELETE FROM Employee WHERE Dno IN(6,7,8);
SELECT MAX(Salary) FROM Employee WHERE Salary NOT IN (SELECT MAX(Salary) FROM Employee);  --Find Second Highest



-- Retrive Students ID whose grade is A or B
SELECT studID FROM Enroll WHERE Grade = 'A'
    UNION
SELECT studID FROM Enroll WHERE Grade = 'B';

-- Retrive Students ID whose grade is A And B
SELECT studID FROM Enroll WHERE Grade = 'A'
    INTERSECT
SELECT studID FROM Enroll WHERE Grade = 'B';

-- Retrieve the list of studID’s who get grade ‘A’ but not grade ‘B’
SELECT studID FROM Enroll WHERE Grade = 'A'
    EXCEPT
SELECT studID FROM Enroll WHERE Grade = 'B';


SELECT * FROM Emp WHERE salary BETWEEN 30000 AND 50000;
-- ❖ Insert records into Sample table from Emp table whose salary is between 20000 and 30000 given that both tables have same structure
INSERT INTO DEPT(SELECT * FROM Emp WHERE salary BETWEEN 20000 AND 30000);
SELECT * FROM Emp WHERE salary NOT BETWEEN 30000 AND 50000; 

SELECT * FROM Emp WHERE emp_name BETWEEN 'A' AND 'D';
SELECT * FROM Emp WHERE hire-date BETWEEN '01-JAN-2022' AND '31-DEC-2022'




CREATE TABLE Stu_IT AS (SELECT stud_name, stud_id
  FROM Student, Dept
  WHERE dept = dept_id AND dept_name = 'IT'
);    --It will store whole table

CREATE VIEW CEStudents AS (SELECT stud_name, stud_id
  FROM Student, Dept
  WHERE dept = dept_id AND dept_name = 'CE'
);    --It's virtual Table based on ResultSet of SQL Statement


-- Find out Fnames of all the employees whore salary is greater than all employees in department No: 5
SELECT FNAME FROM Employee
 WHERE Salary > ALL( SELECT Salary FROM Employee
 WHERE Dno = 5
);

-- SubQuery
SELECT Fname, Lname FROM Employee e
  WHERE SSN IN (SELECT Mgrssn FROM Department d);

SELECT DISTINCT essn FROM WORKS_ON
  WHERE (Pno, Hours) IN( SELECT Pno, Hours FROM WORKS_ON
  WHERE essn = 10);

SELECT Name, Marks FROM Student
 WHERE Marks = (SELECT MAX(Marks) FROM Student); 

SELECT MAX(Salary) AS Second_max_Sal FROM Employee
 WHERE Salary < (SELECT MAX(Salary) FROM Employee);
 

-- Find details of the employee with N-th highest salary. (Let N=5)
SELECT * FROM Employee WHERE
  Salary = (SELECT MIN(Salary) FROM Employee WHERE
  Salary IN(SELECT DISTINCT Salary
  FROM Employee
  ORDER BY Salary DESC
  FETCH FIRST 5 ROWS ONLY));


-- Find Name and Dept_id of every employee whose salary is above average in the department.
SELECT E1.Name, E1.Dept_id FROM Employee E1 WHERE
   Salary > (SELECT AVG(Salary) FROM Employee E2
   WHERE E1.Dept_id = E2.Dept_id);

-- : Retrieve the Fname of each employee who has a dependent with the same Fname and same sex as the employee. 
SELECT e.Fname FROM Employee e
   WHERE e.SSN IN ( SELECT d.essn FROM Dependent d
   WHERE e.Fname = d.Dependent_name AND
   e.sex = d.sex );

SELECT e.FNAME FROM Employee e
  WHERE EXISTS( SELECT * FROM Dependent d
  WHERE e.SSN = d.essn AND e.Sex = d.sex AND
  e.FNAME = d.Dependent_name);   

SELECT e.FNAME FROM Employee e
  WHERE NOT EXISTS( SELECT * FROM Dependent d
  WHERE e.SSN = d.essn);  

SELECT e.FNAME FROM Employee e
  WHERE EXISTS( SELECT * FROM Dependent d WHERE e.SSN = d.essn)
  AND EXISTS( SELECT * FROM Department Dept
  WHERE e.SSN = Dept.Mgrssn);  

SELECT d.Name FROM Department d WHERE
   NOT EXISTS (SELECT e.Dept_id FROM Employee e
   WHERE e.Dept_id = d.Dept_id);

SELECT Names, Salary, (SELECT AVG(Salary) FROM Employee e1
   WHERE e1.Dept_id = e2.Dept_id) AS Average
   FROM Employee e2;   

-- Group By
SELECT Dno, AVG(Salary) AS "Average_Salary" FROM Employee GROUP BY Dno;
SELECT Dno FROM EMPLOYEE GROUP BY Dno HAVING AVG(Salary) > 30000   
  

-- For each department that has more than 5 employees retrieve the department name and the number of employees who are making more than 40,000.
SELECT Dname, COUNT(*) FROM Deparmtent, Employee
    WHERE Dnumber = Dno AND Salary > 40000 AND
    Dno IN (SELECT Dno FROM Employee GROUP BY Dno HAVING
    COUNT(*) > 5)
    GROUP BY Dname;


-- NORMAL JOIN:
SELECT * FROM (R JOIN S ON A=C);
-- NATURAL JOIN ( Same as Normal Join with not specify Condition ): 
SELECT * FROM (R NATURAL JOIN S);
-- LEFT OUTER JOIN:
SELECT * FROM (R LEFT OUTER JOIN S ON A=C);
-- RIGHT OUTER JOIN: 
SELECT * FROM (R RIGHT OUTER JOIN S ON A=C);
-- ▪ FULL OUTER JOIN: 
SELECT * FROM (R FULL OUTER JOIN S ON A=C);


SELECT FNAME, LNAME, Address FROM (Employee JOIN Department
  ON Dno = Dnumber) WHERE Dname = 'Research';

SELECT e.LNAME AS "Emp_name" , s.LNAME AS "Sup_Name" FROM
  (Employee e LEFT OUTER JOIN Employee s ON e.Superssn = s.SSN);  

