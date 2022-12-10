""" 
├── manage.py  # project manager, start project, create apps, db management daily using
└── mysite 
    ├── __init__.py
    ├── asgi.py  # connection requests, do not modify
    ├── settings.py # the project configure file. (modify frequently)
    ├── urls.py  # correspondence of URL and methods (modify frequently) 
    └── wsgi.py # connection requests, do not modify
"""

"""
1. what are apps?
  an app is responding for different features
  each app can have an independent database table
Project: (large project always has a lot of app)
  - app, Admin, 
  - app, order management
  - app, website
  - app, API
"""

"""
2. how to create an app? 
 python3 manage.py startapp app01
"""

"""
3. what are in apps?
├── app01
    ├── __init__.py
    ├── admin.py    # do not touch, django default admin manager
    ├── apps.py   # do not touch, for app starting
    ├── migrations  # do not touch
    └── __init__.py
    ├── models.py  # IMPORTANT, db operations.
    ├── tests.py   # do not touch, app testing, partial testing
    └── views.py   # IMPORTANT, functions are in here
"""

"""
4. If coding in app01, we need to go to settings.py to register it
INSTALLED_APPS = [
    'django.contrib.admin',
    'django.contrib.auth',
    'django.contrib.contenttypes',
    'django.contrib.sessions',
    'django.contrib.messages',
    'django.contrib.staticfiles',
    'app01.apps.App01Config'
]
"""

"""
5. The corresponding of URL and view.py
under urls.py
  5.1 
     from app01 import views
  5.2 
     urlpatterns = [
    # path('admin/', admin.site.urls),
    path('index/', views.index),
    ]
"""

"""
6. How to run app?
   6.1 python3 manage.py runserver
   
   6.2 PyCharm, click "run"
"""

"""
7. ORM for MySQL (IMPORTANT: apps MUST register first)
   7.1 pip3 install mysqlclient
   
   7.2 create, update, delete tables (can not create database)
       python3 manage.py makemigrations
       python3 manage.migrate
       
   7.3 update a existed table
       default values are required unless, will be errors
    
   7.4 opt data in the table
       
"""

"""
8. static folder, 
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
"""$$