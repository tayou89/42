#!/bin/sh

chown -R nginx:www-data /var/www/wordpress
chmod -R 755 /var/www/wordpress

chown -R nginx:www-data /var/www/adminer
chmod -R 755 /var/www/adminer

exec "$@"
