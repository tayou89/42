#!/bin/sh

cd django

# python3 manage.py makemigrations
# python3 manage.py makemigrations api

# python3 manage.py migrate

# python3 manage.py runserver 0.0.0.0:8000
gunicorn --bind 0.0.0.0:8001 gameserver.wsgi:application