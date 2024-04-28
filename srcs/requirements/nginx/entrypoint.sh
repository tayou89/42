#!/bin/sh

chown -R nginx:www-data /var/www/html
chmod -R 755 /var/www/html

exec "$@"