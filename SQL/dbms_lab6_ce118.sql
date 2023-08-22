REM   Script: dbms_lab6_ce118
REM   dbms_lab6_ce118

create table client_master    
(client_no varchar2(6),    
name varchar2(20),    
address1 varchar2(30),    
address2 varchar2(30),    
city varchar2(15),    
state varchar2(15),    
pincode number(6),    
bal_due number(10,2)    
) ;

CREATE TABLE Sales_master (    
    Salesman_no VARCHAR2(6) PRIMARY KEY CHECK(Salesman_no LIKE 'S%'),    
    Sal_name VARCHAR2(20) NOT NULL,    
    Address1 VARCHAR2(30) NOT NULL,    
    Address2 VARCHAR2(30) NOT NULL,    
    City VARCHAR2(20),    
    State VARCHAR2(20),    
    Pincode NUMBER(6),    
    Sal_amt NUMBER(8,2) NOT NULL CHECK(Sal_amt > 0),    
    Tgt_to_get NUMBER(6,2) NOT NULL CHECK(Tgt_to_get > 0),    
    Ytd_sales NUMBER(6,2) NOT NULL,    
	Remarks VARCHAR2(60)    
);

alter table client_master add primary key (client_no);

CREATE TABLE Sales_order(    
    S_order_no VARCHAR2(6) PRIMARY KEY CHECK(S_order_no LIKE 'O%'),    
    order_date DATE NOT NULL,    
    Client_no VARCHAR2(6) references client_master(client_no),    
    Dely_add VARCHAR2(25),    
    Salesman_no VARCHAR2(6) references sales_master(salesman_no),    
    Dely_type CHAR(1) DEFAULT 'F' CHECK(Dely_type IN ('P','F')),    
    Bill_yn CHAR(1),    
    Dely_date DATE,    
    Order_status VARCHAR2(10) CHECK(Order_status IN ('in process','fulfilled',    
    												 'back order','cancelled')),    
    CHECK(Dely_date >= order_date)    
);

create table product_master    
(product_no varchar2(6),    
description varchar2(15),    
profit_percent number(4,2),    
unit_measure varchar2(10),    
qty_on_hand number(8),    
reorder_lvl number(8),    
sell_price number(8,2),    
cost_price number(8,2)    
);

alter table product_master add primary key (product_no);

CREATE TABLE Sales_order_details (   
    S_order_no VARCHAR2(6) references sales_order(S_order_no),   
    Product_no VARCHAR2(6) references product_master(product_no),   
    Qty_order NUMBER(8),   
    Qty_disp NUMBER(8),   
    Product_rate NUMBER(10,2)   
);

insert into client_master (client_no, name, address1, address2, city, state, pincode, bal_due) values ('0001', 'Ivan', 'A/2', 'Worli', 'Bombay', 'Maharashtra', 400054, 15000) ;

insert into client_master (client_no, name, address1, address2, city, state, pincode, bal_due) values ('0002', 'Vandana', 'B/2', 'Juhu', 'Madras', 'Tamilnadu', 780001, 0) ;

insert into client_master (client_no, name, address1, address2, city, state, pincode, bal_due) values ('0003', 'Pramada', 'C/4', 'Nariman', 'Bombay', 'Maharashtra', 400057 ,5000) ;

insert into client_master (client_no, name, address1, address2, city, state, pincode, bal_due) values ('0004', 'Basu', 'A/5', 'Bandra', 'Bombay', 'Maharashtra', 400056,  0) ;

insert into client_master (client_no, name, address1, address2, city, state, pincode, bal_due) values ('0005', 'Ravi', 'E/10', 'Delhi', 'Delhi', 'Delhi', 100001, 2000) ;

insert into client_master (client_no, name, address1, address2, city, state, pincode, bal_due) values ('0006', 'Rukmini', 'B/6', 'Juhu', 'Bombay', 'Maharashtra', 400050, 0) ;

insert into product_master (product_no, description, profit_percent, unit_measure, qty_on_hand, reorder_lvl, sell_price, cost_price) values ('P00001', '1.44floppies', 5, 'piece', 100, 20, 525, 500) ;

insert into product_master (product_no, description, profit_percent, unit_measure, qty_on_hand, reorder_lvl, sell_price, cost_price) values ('P03453', 'Monitors', 6, 'piece', 10, 3, 12000, 11200) ;

insert into product_master (product_no, description, profit_percent, unit_measure, qty_on_hand, reorder_lvl, sell_price, cost_price) values ('P06734', 'Mouse', 5, 'piece', 20, 5, 1050, 500) ;

insert into product_master (product_no, description, profit_percent, unit_measure, qty_on_hand, reorder_lvl, sell_price, cost_price) values ('P07865', '1.22 floppies', 5, 'piece', 100, 20, 525, 500) ;

insert into product_master (product_no, description, profit_percent, unit_measure, qty_on_hand, reorder_lvl, sell_price, cost_price) values ('P07868', 'Keyboards', 2, 'piece', 10, 3, 3150, 3050) ;

insert into product_master (product_no, description, profit_percent, unit_measure, qty_on_hand, reorder_lvl, sell_price, cost_price) values ('P07885', 'CD Drive', 2.5, 'piece', 10, 3, 5250, 5100) ;

insert into product_master (product_no, description, profit_percent, unit_measure, qty_on_hand, reorder_lvl, sell_price, cost_price) values ('P07965', '540 HDD', 4, 'piece', 10, 3, 8400, 8000) ;

insert into product_master (product_no, description, profit_percent, unit_measure, qty_on_hand, reorder_lvl, sell_price, cost_price) values ('P07975', '1.44 Drive', 5, 'piece', 10, 3, 1050, 1000) ;

insert into product_master (product_no, description, profit_percent, unit_measure, qty_on_hand, reorder_lvl, sell_price, cost_price) values ('P08865', '1.22 Drive', 5, 'piece', 2, 3, 1050, 1000) ;

INSERT INTO sales_master VALUES (    
    'S00001' , 'Aman' , 'A/14' , 'Worli' , 'Mumbai' , 'Maharashtra' ,     
    400002 , 3000 , 100 , 50 , 'Good'    
) ;

INSERT INTO sales_master VALUES (    
    'S00002' , 'Omkar' , '65' , 'Nariman' , 'Mumbai' , 'Maharashtra' ,     
    400001 , 3000 , 200 , 100 , 'Good'    
) ;

INSERT INTO sales_master VALUES (    
    'S00003' , 'Raj' , 'P-7' , 'Bandra' , 'Mumbai' , 'Maharashtra' ,     
    400032 , 3000 , 200 , 100 , 'Good'    
) ;

INSERT INTO sales_master VALUES (    
    'S00004' , 'Ashish' , 'A/5' , 'Juhu' , 'Mumbai' , 'Maharashtra' ,     
    400044 , 3500 , 200 , 150 , 'Good'    
) ;

insert into Sales_order (S_order_no, order_date, Client_no, Dely_add, Salesman_no, Dely_type, Bill_yn, Dely_date, Order_status) values ('O19001', '12-jan-96', '0001', ' ', 'S00001','F', 'N', '20-jan-96', 'in process') ;

insert into Sales_order (S_order_no, order_date, Client_no, Dely_add, Salesman_no, Dely_type, Bill_yn, Dely_date, Order_status) values ('O19002', '25-jan-96', '0002', ' ', 'S00002','P', 'N', '27-jan-96', 'cancelled') ;

insert into Sales_order (S_order_no, order_date, Client_no, Dely_add, Salesman_no, Dely_type, Bill_yn, Dely_date, Order_status) values ('O16865', '18-feb-96', '0003', ' ', 'S00003','F', 'Y', '20-feb-96', 'fulfilled') ;

insert into Sales_order (S_order_no, order_date, Client_no, Dely_add, Salesman_no, Dely_type, Bill_yn, Dely_date, Order_status) values ('O19003', '03-apr-96', '0001', ' ', 'S00001','F', 'Y', '07-apr-96', 'fulfilled') ;

insert into Sales_order (S_order_no, order_date, Client_no, Dely_add, Salesman_no, Dely_type, Bill_yn, Dely_date, Order_status) values ('O46866', '20-may-96', '0004', ' ', 'S00002','P', 'N', '22-may-96', 'cancelled') ;

insert into Sales_order (S_order_no, order_date, Client_no, Dely_add, Salesman_no, Dely_type, Bill_yn, Dely_date, Order_status) values ('O10008', '24-may-96', '0005', ' ', 'S00004','F', 'N', '26-may-96', 'in process') ;

INSERT INTO Sales_order_details VALUES(   
  	'O19001' , 'P00001' , 4 , 4 , 525   
) ;

INSERT INTO Sales_order_details VALUES(   
  	'O19001' , 'P07965' , 2 , 1 , 8400   
) ;

INSERT INTO Sales_order_details VALUES(   
  	'O19001' , 'P07885' , 2 , 1 , 5250   
) ;

INSERT INTO Sales_order_details VALUES(   
  	'O19002' , 'P00001' , 10 , 0 , 525   
) ;

INSERT INTO Sales_order_details VALUES(   
  	'O16865' , 'P07868' , 3 , 3 , 3150   
) ;

INSERT INTO Sales_order_details VALUES(   
  	'O16865' , 'P07885' , 10 , 10 , 5250   
) ;

INSERT INTO Sales_order_details VALUES(   
  	'O19003' , 'P00001' , 4 , 4 , 1050   
) ;

INSERT INTO Sales_order_details VALUES(   
  	'O19003' , 'P03453' , 2 , 2 , 1050   
) ;

INSERT INTO Sales_order_details VALUES(   
  	'O46866' , 'P06734' , 1 , 1 , 12000   
) ;

INSERT INTO Sales_order_details VALUES(   
  	'O46866' , 'P07865' , 1 , 0 , 8400   
) ;

INSERT INTO Sales_order_details VALUES(   
  	'O10008' , 'P07975' , 1 , 0 , 1050   
) ;

INSERT INTO Sales_order_details VALUES(   
  	'O10008' , 'P00001' , 10 , 5 , 525   
) ;

SELECT distinct p.description 
FROM product_master p 
JOIN Sales_order_details sod ON p.product_no = sod.product_no 
JOIN Sales_order so ON sod.S_order_no = so.S_order_no 
JOIN client_master c ON so.Client_no = c.client_no 
WHERE c.name = 'Ivan';

SELECT name FROM Sales_order_details NATURAL JOIN 
Sales_order NATURAL JOIN product_master NATURAL JOIN 
client_master WHERE description IN ('CD Drive');

SELECT product_no,S_order_no FROM Sales_order_details 
NATURAL JOIN Sales_order NATURAL JOIN product_master 
WHERE Qty_order < 5 AND description IN ('1.44floppies');

SELECT description, SUM(Qty_order) FROM Sales_order_details 
NATURAL JOIN Sales_order NATURAL JOIN product_master 
NATURAL JOIN client_master 
WHERE name IN ('Ivan', 'Vandana') GROUP BY description;

SELECT description, SUM(Qty_order) FROM Sales_order_details 
NATURAL JOIN Sales_order NATURAL JOIN product_master 
NATURAL JOIN client_master 
WHERE client_no IN ('0001', '0002') GROUP BY description;

SELECT client_no,COUNT(DISTINCT Salesman_no ) FROM 
client_master NATURAL JOIN Sales_order GROUP BY client_no 
HAVING COUNT(Salesman_no) > 0;

SELECT client_no,COUNT(DISTINCT Salesman_no ) FROM 
client_master NATURAL JOIN Sales_order GROUP BY client_no 
HAVING COUNT(Salesman_no) > 0;

SELECT S_order_no,TO_CHAR(order_date ,'Day') AS day FROM 
client_master NATURAL JOIN Sales_order;

SELECT client_no,COUNT(DISTINCT Salesman_no ) FROM 
client_master NATURAL JOIN Sales_order GROUP BY client_no 
HAVING COUNT(Salesman_no) > 0;

SELECT SYSDATE + 15 FROM DUAL;

SELECT S_order_no,TO_CHAR(order_date ,'Day') AS day FROM 
client_master NATURAL JOIN Sales_order;

SELECT S_order_no,TO_CHAR(Dely_date ,'MONTH') , 
TO_CHAR(Dely_date ,'dd-MON-yy') AS MONTH FROM client_master 
NATURAL JOIN Sales_order;

SELECT DISTINCT product_no,description FROM 
Sales_order_details NATURAL JOIN Sales_order NATURAL JOIN 
product_master WHERE Order_status IN ('in process');

SELECT description, SUM(sod.Qty_order) AS total_quantity 
FROM Sales_order_details sod 
JOIN Sales_order so ON sod.S_order_no = so.S_order_no 
WHERE EXTRACT(MONTH FROM so.order_date) = 1 
GROUP BY description;

SELECT sod.description, SUM(sod.Qty_order) AS total_quantity 
FROM Sales_order_details sod 
JOIN Sales_order so ON sod.S_order_no = so.S_order_no 
WHERE EXTRACT(MONTH FROM so.order_date) = 1 
GROUP BY description;

SELECT sod.description, SUM(sod.Qty_order) AS total_quantity 
FROM Sales_order_details sod 
JOIN Sales_order so ON sod.S_order_no = so.S_order_no 
WHERE EXTRACT(MONTH FROM so.order_date) = 1 
GROUP BY description;

select * from Sales_order Natural Join Sales_order_details;

SELECT distinct p.description 
FROM product_master p 
JOIN Sales_order_details sod ON p.product_no = sod.product_no 
JOIN Sales_order so ON sod.S_order_no = so.S_order_no 
JOIN client_master c ON so.Client_no = c.client_no 
WHERE c.name = 'Ivan';

select * from Sales_order Natural Join Sales_order_details;

SELECT DISTINCT description,Qty_order FROM Sales_order_details 
NATURAL JOIN Sales_order NATURAL JOIN product_master 
WHERE TO_CHAR(Dely_date,'MON') = 'JAN';

SELECT DISTINCT description,Qty_order FROM Sales_order_details 
NATURAL JOIN Sales_order NATURAL JOIN product_master 
WHERE TO_CHAR(Dely_date,'MON') = 'JAN' and order_status <> 'cancelled';

SELECT sod.description, SUM(sod.Qty_order) AS total_quantity 
FROM Sales_order_details sod 
JOIN Sales_order so ON sod.S_order_no = so.S_order_no 
WHERE EXTRACT(MONTH FROM so.order_date) = 1 
GROUP BY description;

select * from Sales_order Natural Join Sales_order_details;

select * from sales_order;

select * from sales_order_details;

SELECT DISTINCT product_no,description FROM 
Sales_order_details NATURAL JOIN Sales_order NATURAL JOIN 
product_master WHERE Order_status IN ('in process');

SELECT DISTINCT product_no,description FROM 
Sales_order_details NATURAL JOIN Sales_order NATURAL JOIN 
product_master WHERE Order_status IN ('in process') and qty_display <> 0;

SELECT DISTINCT product_no,description FROM 
Sales_order_details NATURAL JOIN Sales_order NATURAL JOIN 
product_master WHERE Order_status IN ('in process') and qty_disp <> 0;

