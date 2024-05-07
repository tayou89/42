#!/bin/sh

chown -R www-data:www-data /var/www/wordpress
chown -R www-data:www-data /run/php
chmod -R 755 /var/www/wordpress

exec "$@"

