#!/bin/sh

if [ ! -f /var/www/gunicorn/test.py ]; then
	mv /test.py /var/www/gunicorn
	chown -R www-data:www-data /var/www/gunicorn
	chmod 755 /var/www/gunicorn
fi

exec "$@"
