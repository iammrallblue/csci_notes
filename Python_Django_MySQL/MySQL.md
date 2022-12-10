# MySQL Notes

<details>

<summary> Table of Contents</summary>

- [Getting Started]()

- MySQL Install & Configuration

  - [MySQL Basic Installation](#installation-macos)
  - Version 8.x
  - Version 5.x

- [MySQL Start & Shutoff](#launch-mysql)

- MySQL Management

  - [MySQL Statement](#database-management)

- 3rd module for the operation of MySQL (Python)

Forget Password

</details>

- Python Relatives: Basic, Function, Datatypes, OOP, Modules
- Front-end: HTML, CSS, JS, jQuery, Static

```Languages + Frontend
    Java+FE, Python+FE, Go+FE --> Produce Dynamic Pages.
```

- Database, request, response

```Databases
    MySQL, Oracle, SQLServer, DB2, Access ...
```

## Installation (macOS)

```brew
    brew install mysql
    brew install --cask mysqlworkbench
```

## Launch MySQL

```

```

## Connection MySQL

Step 1. Login to the `MySQL` database.

```sql
    > mysql -u root -p
        -- Enter password: **********
    mysql>

```

Step 2. Issue the USE command to switch to the `MySQL` database to classic models:

```sql
    mysql> USE DB_name;
    
    Database changed
    mysql>
```

## Forget `MySQL` password

```

```

## Create a `Database`
```sql
    -- create a database
    create database db_name;
    -- create a user ONLY for the specified database
    create user 'user'@'localhost' identified by 'password';
    -- setup user privileges for read and write of the specified database
    grant all privileges on *.* to 'user'@'localhost';
```

## Database Management

Show Existed Databases

```sql
    show databases;
```

Create a Database

```sql
    create database db_name DEFAULT CHARSET utf8 COLLATE utf8_general_ci;
```

Drop a Database (delete a database)

```sql
    drop database db_name;
```

Use a Database

```sql
    use db_name;
```

Show tables in the used Database

```sql
    show tables;
```

Create a new table

- `create table tb_name;`

```sql
    create table tb_name(
        column_name type,
        column_name type,
        column_name type
    )default charset=utf8;
```

Example, create a table

```sql
    create table tb_name(
        id int,
        name varchar(16),
        age int
    )default charset=utf8;
```

Example, the constraint columns

- `NOT NULL`, and `NULL`

```sql
    create table tb_name(
        id int,
        name varchar(16) not null, -- this column CANNOT be null
        age int null   -- this column can be null
    )default charset=utf8;
```

Example, set a `default` value to a column

- `default` is usually the column can not be null

```sql
    create table tb_name(
        id int,
        name varchar(16),
        age int default 3 -- if no values is inserted, the default value is 3
    )default charset=utf8;
```

Example, set a `primary key` for a column

- `primary key` **CANNOT** be `NULL`, **CANNOT** be duplicated.
- `primary key` is usually set `auto_increment` which is self increment

```sql
    create table tb_name(
        id int, auto_increment primary key, -- not null, not duplicated
        name varchar(16),
        age int
    )default charset=utf8;
```

Example, Drop a table

- `drop table` is to delete a table from database

```sql
    drop table tb_name;
```

Example, Show all columns from a table

- `desc tb_name;` `desc` is to show a table

```sql
    mysql> desc tb2;
    +--------+-------------+------+-----+---------+----------------+
    | Field  | Type        | Null | Key | Default | Extra          |
    +--------+-------------+------+-----+---------+----------------+
    | id     | bigint      | NO   | PRI | NULL    | auto_increment |
    | name   | varchar(16) | YES  |     | NULL    |                |
    | salary | int         | YES  |     | NULL    |                |
    | age    | tinyint     | YES  |     | NULL    |                |
    +--------+-------------+------+-----+---------+----------------+
    4 rows in set (0.00 sec)

```

## Common Datatypes

- `tinyint`, `int`, `bigint`
- `float`, `double`, `decimal`
- `char`, `varchar`, `text`, `mediumtext`, `longtext`
- `datetime`, `date`

### tinyint

- tinyint, `tinyint` is a very small integer
- storage, **1 bytes**
- signed min_value to max_value, -128 to 127 {Default}
- unsigned min_value to max_value, 0 to 255

```sql
    create table tb_tinyint(
        id int not null primary key auto_increment,
        age tinyint -- default is a signed tinyint type
        age tinyint unsigned -- specified age is a unsigned tinyint type
    )default charset=utf8;
```

### int

- int, `int` is a standard integer
- storage, **4 bytes**
- signed min_value to max_value, -2147483648 to 2147483647
- unsigned min_value to max_value, 0 to 4294967295

```sql

```

### bigint

- bigint, `bigint` is a large integer
- storage, **8 bytes**

```sql
    signed min_value to max_value,  -9223372036854775808 to 9223372036854775807
    unsigned min_value to max_value, 0 to 18446744073709551615

    create table tb_bigint(
        id bigint not null auto_increment primary key,
        salary int,
        age tinyint
    )default charset=utf8;
```

Example, Insert values to columns `salary` and `age`

```sql
    insert into tb_bigint(salary, age) values(10000,18); -- insert a row value
    insert into tb_bigint(salary, age) values(20000,19), (30000,20),(40000,21);
    -- insert multiple row values.

```

Example, Check/View the values in a table

```sql
    select * form tb_bigint;
```

```sql
    mysql> select * from tb_bigint;
    +----+--------+------+
    | id | salary | age  |
    +----+--------+------+
    |  1 |  10000 |   18 |
    |  2 |  20000 |   19 |
    |  3 |  30000 |   20 |
    |  4 |  40000 |   21 |
    +----+--------+------+
    4 rows in set (0.00 sec)

```

### decimal

### float

### double

### char

- `char`, char is a fixed-length nonbinary (character) string
- **char(11)** can hold up to 11 characters. ONLY 11 characters, over 11 "Data too long for column"

```sql
    create table tb_char(
        id int not null primary key auto_increment,
        mobile char(11),
        status char(3)
    )default charset=utf8;

    insert into tb_char(mobile,status) values("6787011000", 'Yes'),("6787012000",'No'), ("6787013000",'Yes');
```

### varchar

- `varchar`, varchar is a variable-length non-binary string whose length can be up to 65,535
- varchar is more save memory space

```sql
    create table tb_varchar(
        id int not null primary key auto_increment,
        mobile varchar(11)
    )default charset=utf8;

    insert into tb_varcahr(moible) values("678"), ("6785101000");
```

### text

### mediumtext

### longtext

### datetime

- A date and time value in `YYYY-MM-DD hh:mm:ss `format

### date

- A date value in `YYYY-MM-DD` format

Example, Datatypes

```sql
    create table tb7(
        id int not null primary key auto_increment,
        name varchar(64) not null,
        password char(64) not null,
        email varchar(64) not null,
        age tinyint,
        salary decimal(10,2),
        ctime datetime
    )default charset=utf8;

```

- `insert` values to table tb7

```sql
    insert into tb7(name, password,email,age, salary, ctime) values("Bella", "bella123", "bella.h@live.com", 18, 10000.00, "1999-01-01 11:11:11");
```

- `select` values from table tb7

```sql
    mysql> select * from tb7;
    +----+-------+----------+------------------+------+----------+---------------------+
    | id | name  | password | email            | age  | salary   | ctime               |
    +----+-------+----------+------------------+------+----------+---------------------+
    |  1 | Bella | bella123 | bella.h@live.com |   18 | 10000.00 | 1999-01-01 11:11:11 |
    +----+-------+----------+------------------+------+----------+---------------------+
    1 row in set (0.00 sec)
```

- `delete` values from table tb7

```sql
    delete from * tb7;
    delete from * where conditon;

    delete from tb7;
    delete from tb7 where id = 3;
    delete from tb7 where id = 4 and name="Bella"
    delete from tb7 where id = 4 or name="Cathy"
    delete from tb7 where id > 4;
    delete from tb7 where id >= 4;
    delete from tb7 where id != 4;
    delete from tb7 wehre id in (1,5)
```

- `udpate` values in table tb7

```sql
    update tb7 set column_name=value;
    update tb7 set column_name=value, column_name=value;
    update tb7 set column_name where condition;

    update tb7 set password="new_password";
    update tb7 set email="new@email.com" where id > 5;
    update tb7 set age=age+10 where id > 5;
```

- `select` columns from table tb7

```sql
    select * from tb7:
    select col_name, col_name from tb7;
    select col_name, col_name from tb7 where condition:

    select * from tb7;
    select id, name from tb7;
    select id, name from tb7 where id > 10:
    select id, name from tb7 where name="xx" and password="xx":
```

Example, personal management

- Create a database named **`unicom`**

```sql
    create database unicom DEFAULT CHARSET utf8 COLLATE utf8_general_ci;

    mysql> show databases;
    +--------------------+
    | Database           |
    +--------------------+
    | sys                |
    | testDB             |
    | unicom             |
    +--------------------+

```

- Create a table in **`unicom`** named **admin**

```sql
    create table admin(
        id int primary key, auto_increment;
        username varchar(64) not null;
        password varchar(64) not null;
        mobile varchar(64) not null;
    )default charset=utf8;

    mysql> show tables;
    +----------------------------+
    | Tables_in_unicom           |
    +----------------------------+
    | admin                      |
    +----------------------------+
```

```sql
    mysql> select * from admin;
    +----+----------+----------+-----------+
    | id | username | password | mobile    |
    +----+----------+----------+-----------+
    |  1 | Abby     | 1234     | 678000001 |
    |  2 | Bella    | 1234     | 678000101 |
    |  3 | Cathy    | 1234     | 678000100 |
    +----+----------+----------+-----------+
    3 rows in set (0.00 sec)

```

- Implementation in `Python` by `pymysql`
  - Connect to MySQL by using `pymysql`
  - `Insert` data `into` a table
  - `Select` the table to check inserted data
  - `Query` to query MySQL
  - `Delete` data from a table

```Python
    # coding:utf-8
    # 9/20/22 8:13 AM

    import pymysql

    # how to use pymysql

    while True:
        user = input("Username: ")
        if user.upper() == 'Q':
            break
        pwd = input("Password: ")
        mobile = input("Mobile: ")

    # static insert information
    # first step connect to mysql
    db_conn = pymysql.connect(host="127.0.0.1", port=3306, 
    user='root', passwd='******', charset='utf8', db='unicom')
    # cursor sends and receives mysql statements
    cursor = db_conn.cursor(cursor=pymysql.cursors.DictCursor)

    # 2nd, sending mysql statement
    # cursor.execute("insert into admin(username, password, mobile) values('Abby', '1234', '678000001')")
    # db_conn.commit()


    # hazards, methods to void mysql inject

    # 2nd step can be
    sql_insert = "insert into admin(username, password, mobile) values(%s, %s, %s)"  # acceptable
    # cursor.execute(sql_insert, ["Bella", "1234", "678000010"])
    cursor.execute(sql_insert, [user, pwd, mobile]) # request from user input

    # using a dict to insert data
    # sql_insert = "insert into admin(username, password, mobile) values(%(n1)s, %(n2)s, %(n3)s)"  # it's also acceptable
    # cursor.execute(sql_insert, {"n1": "Cathy", "n2": "12345", "n3": "678000100"})

    db_conn.commit()

    # 3rd, close connection and cursor, MUST be executed after MySQL statements are done
    cursor.close()
    db_conn.close()

    # how to insert multiple data

```

```sql
    select * from admin; -- check inserted data

    mysql> select * from admin;
    +----+----------+----------+-----------+
    | id | username | password | mobile    |
    +----+----------+----------+-----------+
    |  1 | Abby     | 1234     | 678000001 |
    |  2 | Bella    | 1234     | 678000101 |
    |  3 | Cathy    | 1234     | 678000100 |
    +----+----------+----------+-----------+
    3 rows in set (0.00 sec)
```

```Python
    # coding:utf-8
    # 9/28/22 7:35 AM
    import pymysql

    # 1st mysql connection
    db_connection = pymysql.connect(host="127.0.0.1",
    port=3306, user='root', passwd='******', charset='utf8', db='unicom')
    cursor = db_connection.cursor(cursor=pymysql.cursors.DictCursor)

    # 2nd sending requests
    # cursor.execute("select * from admin")
    cursor.execute("select * from admin where id > %s, [2, ])

    # to fetch all data from the table
    data_list = cursor.fetchall()
    for row_dict in data_list:
        print(row_dict)

    # 3rd close cursor and connection
    cursor.close()
    db_connection.close()

```
```Python
    # The Result of fetching all data (in Dict)
    # /usr/local/bin/python3.9 /Users/junoh/Workspace/pythonbasic/mysql_execution/query_db.py
    {'id': 1, 'username': 'Abby', 'password': '1234', 'mobile': '678000001'}
    {'id': 2, 'username': 'Bella', 'password': '1234', 'mobile': '678000101'}
    {'id': 3, 'username': 'Cathy', 'password': '1234', 'mobile': '678000100'}
```

```Python
    # coding:utf-8
    # 9/28/22 7:35 AM
    import pymysql

    # 1st mysql connection
    db_connection = pymysql.connect(host="127.0.0.1",
    port=3306, user='root', passwd='******', charset='utf8', db='unicom')
    cursor = db_connection.cursor(cursor=pymysql.cursors.DictCursor)

    # 2nd sending requests
    # cursor.execute("select * from admin")
    cursor.execute("select * from admin where id > 2)

    # to fetch one data form the table
    one_result = cursor.fetchone()
    print(one_result) # result is in dict

    # 3rd close cursor and connection
    cursor.close()
    db_connection.close()
```
```Python
    # The result of fetching one data
    {'id': 3, 'username': 'Cathy', 'password': '1234', 'mobile': '678000100'}
```

```Python
    # coding:utf-8
    # 10/11/22 11:34 AM
    import pymysql

    # first step connect to mysql
    db_conn = pymysql.connect(host="127.0.0.1", port=3306, user='root', passwd='******', charset='utf8', db='unicom')
    cursor = db_conn.cursor(cursor=pymysql.cursors.DictCursor)  # cursor sends and receives mysql statements

    # 2nd sending request
    cursor.execute("delete from admin where id=%s", [3, ])
    db_conn.commit()

    # 3rd close connect and cursor
    cursor.close()
    db_conn.close()
```

```Python
    # coding:utf-8
    # 10/11/22 11:34 AM
    import pymysql
    
    # 1st, conenct to MySQL
    conn = pymysql.connect(host="127.0.0.1", port=3306, user='root', passwd="******"
    charset='utf8', db='unicom')
    cursor = conn.cursor (cursor=pymysql.cursors.DictCursor)

    # 2nd sending update request
    cursor.execute ("update admin set mobile=%s where id=%s", ["1888888888", 4, ])
    conn.commit()

    # 3rd, close connection and cursor
    cursor.close()
    conn.close()

```

### MySQL Dead Loop
- To solve dead loops caused by insert statement
```sql
    -- to empty a table
    SET FOREIGN_KEY_CHECKS = 0;
    TRUNCATE TABLE ebooking.seat;
    SET FOREIGN_KEY_CHECKS = 1;

    -- to delete all records from a table 
    SET FOREIGN_KEY_CHECKS = 0;
    DELETE
    FROM ebooking.seat;
    SET Foreign_Key_Checks = 1;

    SHOW PROCESSLIST;
    KILL 28; # 28 is process id
    KILL 70;
    KILL 75;

    -- show the current database privileges.
    SHOW GRANTS;
    
```

### Demo of Creating seats for each Showroom

```sql
USE ebooking;
/* For Mysql workbench. */
DROP PROCEDURE IF EXISTS proc_init_seats;

DELIMITER  $
# the procedure for initialing seats
CREATE PROCEDURE proc_init_seats()
BEGIN
    DECLARE i INT; # i is row
    DECLARE j INT; # j is seat
    DECLARE room_number INT; # show room number
    DECLARE n_row INT;
    DECLARE seat_per_row INT;

    DECLARE done BOOLEAN DEFAULT 0;
    # get fields from the table show_room
    DECLARE cursor_room CURSOR FOR SELECT show_room_id, number_of_row, seats_per_row FROM ebooking.show_room;
    DECLARE CONTINUE HANDLER FOR SQLSTATE '02000' SET done = 1;
    OPEN cursor_room;
    REPEAT
        FETCH cursor_room INTO room_number, n_row, seat_per_row; # fetch fields from the table show_room
    IF NOT done THEN
     SET i = 1;
     SET j = 1;
     WHILE (i <= n_row) # 5 rows
       DO
         WHILE (j <= seat_per_row) # 10 seats for each row
           DO
             INSERT INTO ebooking.seat(`row`, number, show_room_id) VALUES (i, j, room_number);
             SET j = j + 1;
           END WHILE;
         SET i = i + 1;
         SET j = 1;
       END WHILE;
     END IF;
    UNTIL done = 1 END REPEAT;
    CLOSE cursor_room;
END ;
$
DELIMITER ;

CALL proc_init_seats();
/* For Mysql workbench. */
```

```sql
USE ebooking;
/* For PyCharm. */
DROP PROCEDURE IF EXISTS proc_init_seats;

DELIMITER  $ 
# the procedure for initialing seats
CREATE PROCEDURE proc_init_seats()
BEGIN
    DECLARE i INT; # i is row
    DECLARE j INT; # j is seat
    DECLARE room_number INT; # show room number
    DECLARE n_row INT;
    DECLARE seat_per_row INT;

    DECLARE done BOOLEAN DEFAULT 0;
    # get fields from the table show_room
    DECLARE cursor_room CURSOR FOR SELECT show_room_id, number_of_row, seats_per_row FROM ebooking.show_room;
    DECLARE CONTINUE HANDLER FOR SQLSTATE '02000' SET done = 1;
    OPEN cursor_room;
    REPEAT
        FETCH cursor_room INTO room_number, n_row, seat_per_row; # fetch fields from the table show_room
        IF NOT done THEN
            SELECT room_number, n_row, seat_per_row;
            SET i = 1;
            SET j = 1;
            WHILE (i <= n_row) # 5 rows
                DO
                    WHILE (j <= seat_per_row) # 10 seats for each row
                        DO
                            INSERT INTO ebooking.seat(`row`, number, show_room_id) VALUES (i, j, room_number);
                            SET j = j + 1;
                        END WHILE;
                    SET i = i + 1;
                    SET j = 1;
                END WHILE;
        END IF;
    UNTIL done = 1 END REPEAT;
    CLOSE cursor_room;
END $

DELIMITER ;

CALL proc_init_seats();
/* For PyCharm. */

```