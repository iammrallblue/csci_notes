# Table of Content

<details>

<summary> Table of Contents</summary>

- [Table of Content](#table-of-content)
  - [Getting Started](#getting-started)
  - [Django ORM Module](#django-orm-module)
    - [`mysqlclient` installation](#mysqlclient-installation)
    - [`ORM` module - **Object-relational mapper**](#orm-module---object-relational-mapper)
    - [Connect to MySQL using **`Django ORM`**](#connect-to-mysql-using-django-orm)
    - [Using classes in `models.py` file to create a table in MySQL](#using-classes-in-modelspy-file-to-create-a-table-in-mysql)
    - [Running commands to create tables](#running-commands-to-create-tables)
    - [Add new column to a existed table](#add-new-column-to-a-existed-table)
    - [Operating values in the columns](#operating-values-in-the-columns)

</details>

## Getting Started

## Django ORM Module

### `mysqlclient` installation

- `Terminal`, to install **mysqlclient** by pip

  ```sh
    pip install mysqlclient
    # or
    pip3 install mysqlclient
  ```

### `ORM` module - **Object-relational mapper**

- `ORM` CANNOT create a database, manually create a **database** by MySQL statements

  - create a database

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

- `ORM` can do `CRUD` tables
- `ORM` can do `CRUD` data in tables
- `ORM` can operate MySQL, DONOT need to write `MySQL` statements

### Connect to MySQL using **`Django ORM`**

- `settings.py`, and `models.py` files are involved.

- Add the `DATABASES` config to `settings.py` file

```python
# config the connection for MySQL, in the settings.py
DATABASES = {
  'default': {
      'ENGINE': 'django.db.backends.mysql',
      'NAME': 'unicom',
      'USER': 'root',
      'PASSWORD': '******',
      'HOST': '127.0.0.1',
      'PORT': 3306,
  }
}
```

### Using classes in `models.py` file to create a table in MySQL

- In the `models.py` file, create classes for **MySQL** operations
- <span style="color:red">IMPORTANT: </span>All database operations are existing as classes in `models.py` file

```python
from django.db import models
# Create your models here.
# this class UserInfo is for creating a table nameed "app01_userinfo" in the database
class UserInfo(models.Model):
 name = models.CharField(max_length=32)
 password = models.CharField(max_length=64)
 age = models.IntegerField()
```

### Running commands to create tables

- `makemigrations`, and `migrate` commands are used

  ```sh
    # create, update, delete tables (can not create database)
    python3 manage.py makemigrations

    python3 manage.migrate
    # these two commands are for creating tables in the database
  ```

- The result in the database after above two commands are executed.

```sql
    -- Above two codes can make a new table named userifo in the database
    mysql> desc app01_userinfo;
    +----------+-------------+------+-----+---------+----------------+
    | Field    | Type        | Null | Key | Default | Extra          |
    +----------+-------------+------+-----+---------+----------------+
    | id       | bigint      | NO   | PRI | NULL    | auto_increment |
    | name     | varchar(32) | NO   |     | NULL    |                |
    | password | varchar(64) | NO   |     | NULL    |                |
    | age      | int         | NO   |     | NULL    |                |
    +----------+-------------+------+-----+---------+----------------+
    4 rows in set (0.00 sec)
```

### Add new column to a existed table

- The table `app01_userinfo` is involved
- Add a column **`size`** to the table

```python
"""
    Create class UserInfo to create the table in the database,
    same as the MySQL statements
    the tablle name "app01_userinfo"
"""
# class UserInfo inherited from class Model
class UserInfo(models.Model):
 # these are columns will be created inside table "app01_userinfo.
 name = models.CharField(max_length=32)
 password = models.CharField(max_length=64)
 age = models.IntegerField()

    """
        Adding new columns to the existing tables, Methods to avoid errors
        Three methods to avoid columns without values:
            1. Assigning values during the program execution
            2. Adding columns with the default values
            3. Adding columns with the null value == True
    """
 # size is a new column that added after table created,
 # size column does not have default value, or null value is set
 size = models.IntegerField()

 # 2. create dob column with the default value,
 dob = models.IntegerField(default=2)

 # 3. the default value of a new column "data" is set to null
 data = models.IntegerField(null=True, blank=True)

```

- Create a **table** named `app01_userinfo` by MySQL statements

```sql
-- the class UserInfo is same functioning as these MySQL statements
create table app01_userinfo(
    id bigint auto_increment primary key,
    name varchar(32),
    password varchar(64),
    age int
)default charset=utf8;
```

### Operating values in the columns

- `models.py`, `views.py`, `urls.py` and files are invloved.
- Create a new **table** named `app01_department` in the `models.py` by creating class **Department**
- the Class `Department` is the table in the database

```python
    # create a table with one column in the database
    class Department(models.Model):
 title = models.CharField(max_length=32)
```

- Insert values to the column `title` and the columns `name`, `password`, and `age`

```python
    # insert a new value of the column title
    # same as insert into app01_department(title) values("Sales Dept.");
    Department.objects.create(title="Sales Dept.")

    # insert values to columns(name, password, age)
    # same as insert into app01_userinfo(name,password,age) values("Nate","123",20);
    UserInfo.objects.create(name="Nate", password="123", age=20, )
```

```sql
    insert into app01_department(title) values("Sales Dept.");

    insert into app01_userinfo(name, password, age) values("Nate","123", 20);
```

- Testing `ORM` add a **path** to `urls.py` file

```python
   # test ORM database
    path('orm/', views.orm),
```

- Adding a view function to `views.py` file for operating values in the columns

```python
    def orm(request):
        # ORM operations for the values in tables (create, insert, update, delete)
        # add values to the column title
        Department.objects.create(title="SaleDept")
        Department.objects.create(title="ITDept")
        Department.objects.create(title="OptDept")

        return HttpResponse("Submitted.")
```
