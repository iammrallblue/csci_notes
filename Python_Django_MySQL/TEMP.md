- [CSCI4050 Term Project](#csci4050-term-project)
  - [Overview](#overview)
  - [Quick Start](#quick-start)
  - [Reset mysql root password in Mac OS:](#reset-mysql-root-password-in-mac-os)
  - [First Stop MySQL:](#first-stop-mysql)
  - [Process to Reset MySQL Root Pass in Mac:](#process-to-reset-mysql-root-pass-in-mac)
  - [Update: On 8.0.15 (maybe already before that version) the PASSWORD() function does not work You have to do:](#update-on-8015-maybe-already-before-that-version-the-password-function-does-not-work-you-have-to-do)
    - [Works for M1 MacBook](#works-for-m1-macbook)
    - [MacOSX MySql root Password Reset master solution](#macosx-mysql-root-password-reset-master-solution)


# CSCI4050 Term Project

## Overview

Contains a backend Django app with restful api endpoints.

Contains a frontend Next.js app which fetches data from the api.

## Quick Start

- 1.0 Clone repository

```sh
    git clone https://github.com/keesephillips/termProject.git
```

- 2.0 Set up the backend `Django api`

```sh
    # In a new terminal, cd into the backend directory
    $ cd backend

    # Activate a virtual environment
    $ pip install virtualenv
    # or
    $ pip3 install virtualenv

    $ python3.xx -m venv .venv

```

- 2.1 Windows

```sh
# If Windows:
$ venv\Scripts\activate.bat

# If Linux:
$ source venv/Scripts/activate

```

- 2.2 Packages for the Project

```sh
    # Download necessary packages
    $ python -m pip install -r requirements.txt
    # or
    $ python3.xx -m pip3 install -r requirements.txt
```

```sql
    --  Run MYSQL server locally on port 3306

    -- Connect to server on MySql Workbench

    -- Populate with latest .sql file: "./ebooking_v7.sql"

    -- Create User in MySQL Workbench. Run the following SQL:
    > create user group4c identified by 'g0Dawgs21';

    > grant all on ebooking.* to 'group4c'@'%';
    -- or
    > grant all on ebooking.* to 'group4c'@'localhost';

    > flush privileges;

    > mysqldump --no-tablespaces -ugroup4c -p --databases ebooking > /Users/junoh/Downloads/ebooking_bak.sql
    -- backup mysql 
```

```sh

      # Make database migrations (update)
      $ python3.xx manage.py makemigrations
      $ python3.xx manage.py migrate --run-syncdb
      $ python3.xx manage.py runserver

```

3.) Run the backend server

      $ py manage.py runserver

      # Access the API at 127.0.0.1:8000/api/v1/<ENDPOINT>
      # ENDPOINTS Currently implemented:
          # user
          # customer
          # admin
          # paymentcard

4.) Set up the frontend Next.js app

      # Install node package manager on your system if it is not already installed

      # In a new terminal, cd into the frontend directory
      $ cd frontend

      # Install dependencies
      $ npm install

      # Create a new .env file. This will hold the backend api endpoint
      # In your text editor put the following line in your .env file:
      DJANGO_API=http://localhost:8000/

5.) Run the frontend server

      $ npm run dev

      # Go to http://localhost:3000/backend-test
      # proof of concept demo (this will pull the users from the backend database and display on page)

"""
1. static folder, 
    This folder usually contains css, img, js, and plugins folders
    these folders are for putting the corresponding files.
    *** css, images, js, are always used as static files.
    *** static folder is usually under app folders.
"""

"""
9. template syntax:

"""

"""
10. Django db operation ORM database framework
ORM can do two things
	1. create, alter, drop tables in databases.
		*** CANNOT create databases
	2. insert, update, delete data in tables.
		
	Django(ORM) to connect database that created.
		1. create database
		2. connect to database (setting.py) add DATABASES = { }
		DATABASES = {
            'default': {
                'ENGINE': 'django.db.backends.mysql',
                'NAME': 'unicom',
                'USER': 'root',
                'PASSWORD': 'tyghbn',
                'HOST': '127.0.0.1',
                'PORT': 3306,
    }
}	
"""


## Reset mysql root password in Mac OS:

First Stop MySQL:
------
1. Go to: 'System Preferences' >> 'MySQL' and stop MySQL

OR,

1) sudo /usr/local/mysql/support-files/mysql.server start
2) sudo /usr/local/mysql/support-files/mysql.server stop
3) sudo /usr/local/mysql/support-files/mysql.server status

Process to Reset MySQL Root Pass in Mac:
----------------------
1. Make sure you have Stopped MySQL first (above).
2. Run the server in safe mode with privilege bypass: `sudo mysqld_safe --skip-grant-tables`
3. In a new window connect to the database, set a new password and flush the permissions & quit: `mysql -u root`
4. **For MySQL older than MySQL 5.7 use**: 
   ```sql
   UPDATE mysql.user SET Password=PASSWORD('rootpass') WHERE User='root';
   ``` 

   **For MySQL 5.7+ use:** 
   ```sql 
   UPDATE mysql.user SET authentication_string=PASSWORD("rootpass") WHERE User='root';
   ```	
   
5. Now flush privileges: 
   ```sql
   FLUSH PRIVILEGES;
   ```
6. Restart MySQL server.
7. 
8. **More info:** http://stackoverflow.com/questions/6474775/setting-the-mysql-root-user-password-on-os-x


## Update: On 8.0.15 (maybe already before that version) the PASSWORD() function does not work You have to do:

### Works for M1 MacBook
- Make sure you have Stopped MySQL first (above).
- Run the server in safe mode with privilege bypass: 
```sql 
    > sudo mysqld_safe --skip-grant-tables
    > mysql -u root
    > UPDATE mysql.user SET authentication_string=null WHERE User='root';
    > FLUSH PRIVILEGES;
    > exit;
```

```sql
    -- Then
    > mysql -u root
    > ALTER USER 'root'@'localhost' IDENTIFIED WITH caching_sha2_password BY 'yourpasswd';
    -- This seems to be the correct method for newer MySQL versions but I left root user empty so didn't need the last part 
```

### MacOSX MySql root Password Reset master solution
- Step by step guide
```sh
    $ brew services stop mysql
    $ pkill mysqld
    $ rm -rf /usr/local/var/mysql/ # NOTE: this will delete your existing database!!!
    $ brew postinstall mysql
    $ brew services restart mysql
    $ mysql -u root
```