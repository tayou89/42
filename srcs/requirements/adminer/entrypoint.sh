#!/bin/sh

chown -R www-data:www-data /var/www/adminer
chmod 755 /var/www/adminer/adminer.php

exec "$@"
