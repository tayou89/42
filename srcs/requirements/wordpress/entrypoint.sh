#!/bin/sh

chown -R www-data:www-data /var/www/wordpress
chmod -R 755 /var/www/wordpress

exec "$@"

