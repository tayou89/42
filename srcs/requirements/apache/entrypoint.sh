#!/bin/sh

envsubst '${SSL_CERT_PATH},${SSL_KEY_PATH}'< /etc/apache2/sites-enabled/default.conf.template > /etc/apache2/sites-enabled/000-default.conf

chown -R www-data:www-data /var/www

a2enmod cgi
a2enmod dav
a2enmod dav_fs
a2enmod ssl
a2enmod rewrite
a2enmod macro
a2ensite default-ssl

exec "$@"
