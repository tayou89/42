#!/bin/sh

chown -R www-data:www-data /var/www/html/wordpress
chmod -R 755 /var/www/html/wordpress

exec "$@"

