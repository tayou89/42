#!/bin/sh

chown -R www-data:www-data /var/www/adminer
chown -R www-data:www-data /run/php
chmod 755 /var/www/adminer/adminer.php

exec "$@"
