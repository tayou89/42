#!/bin/sh

rm -rf /var/www/* && mv /web-document/* /var/www && rm -rf /web-document

envsubst '${SSL_CERT_PATH},${SSL_KEY_PATH}'< /etc/apache2/sites-enabled/wordpress.conf.template > /etc/apache2/sites-enabled/wordpress.conf

chown -R www-data:www-data /var/www

a2dismod mpm_event
a2enmod mpm_prefork cgi dav dav_fs ssl rewrite macro 
a2ensite default-ssl

exec "$@"
