#!/bin/sh

envsubst '${SERVER_NAME},${SSL_CERT_PATH},${SSL_KEY_PATH}'< /etc/nginx/http.d/wordpress.conf.template > /etc/nginx/http.d/wordpress.conf

chown -R nginx:www-data /var/www/wordpress
chmod -R 755 /var/www/wordpress

chown -R nginx:www-data /var/www/adminer
chmod -R 755 /var/www/adminer

chown -R nginx:www-data /var/www/gunicorn
chmod -R 755 /var/www/gunicorn

exec "$@"
