REM   Script: dbms_lab5_ce118
REM   dbms_lab5_ce118

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

alter table client_master add primary key (client_no);

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

create table Challan_Details(Challan_no varchar2(6), Product_no varchar2(6), Qty_disp number(4,2) not null, constraint Challan_no foreign key (Challan_no) references Challan_Header(Challan_no), constraint product_no foreign key (Product_No) references product_Master(product_no));

create table Challan_Header(Challan_no varchar2(6), s_order_no varchar2(6), challan_date date not null, billed_yn char(1) default 'N' check(billed_yn in('Y','N')), constraint Challn_no PRIMARY KEY(Challan_no), CONSTRAINT s_ordr_no foreign key (s_order_no) references sales_order(s_order_no));

insert into Challan_Header values('CH9001','O19001','12-DEC-95','Y');

insert into Challan_header values('CH6865','O46866','12-NOV-95','Y');

insert into Challan_header values('CH3965','O10008','12-OCT-95','Y');

Select * from Challan_Header;

alter table client_master add phone_no number(10);

insert into Challan_Details values('CH9001','P00001',4);

insert into Challan_Details values('CH9001','P07965',1);

insert into Challan_Details values('CH9001','P07885',1);

insert into Challan_Details values('CH6865','P07868',3);

insert into Challan_Details values('CH6865','P03453',4);

insert into Challan_Details values('CH6865','P00001',10);

insert into Challan_Details values('CH3965','P00001',5);

insert into Challan_Details values('CH3965','P07975',2);

Select * from Challan_Details;

alter table product_master modify description varchar2(15) not null;

alter table product_master modify sell_price number not null;

alter table product_master modify profit_percent number not null;

alter table product_master modify cost_price number not null;

alter table client_master modify client_no varchar2(10);

alter table challan_header drop constraint s_order_no;

alter table challan_header drop constraint s_ordr_no;

