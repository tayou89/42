#!/bin/sh

chown -R www-data:www-data /etc/exim4
chmod 755 -R /etc/exim4

container_ip=$(ip addr show eth0 | grep 'inet\b' | awk '{print $2}')

sed -i "s|^dc_relay_nets=.*$|dc_relay_nets='$container_ip'|" /etc/exim4/update-exim4.conf.conf

echo "smtp.gmail.com:$GMAIL_LOGIN:$GMAIL_PASSWORD" > /etc/exim4/passwd.client

update-exim4.conf

exec "$@"
