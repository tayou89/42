#!/bin/sh

mkdir -p /var/www/adminer /usr/log 
touch /usr/log/www.access.log
wget "http://www.adminer.org/latest.php" -O /var/www/adminer/adminer.php
mkdir -p /run/php 
mv /adminer.php /var/www/adminer

chown -R www-data:www-data /var/www/adminer
chown -R www-data:www-data /run/php
chmod 755 /var/www/adminer/adminer.php

exec "$@"
