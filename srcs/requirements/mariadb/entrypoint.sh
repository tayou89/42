#!/bin/sh

if [ ! -d /var/run/mysqld ]; then
	mkdir -p /var/run/mysqld
fi

chown -R mysql:mysql /var/run/mysqld /var/lib/mysql
chmod 777 /var/run/mysqld

echo "Starting MariaDB with settings:"
echo "Database: ${DATABASE_NAME}"
echo "User: ${DATABASE_USER}@${DATABASE_HOST}"

mysql -e "CREATE DATABASE ${DATABASE_NAME};"
mysql -e "CREATE USER ${DATABASE_USER}@${DATABASE_HOST} IDENTIFIED BY '${DATABASE_PASSWORD}';"
mysql -e "GRANT ALL PRIVILEGES ON ${DATABASE_NAME}.* TO ${DATABASE_USER}@${DATABASE_HOST};"
mysql -e "FLUSH PRIVILEGES;"

exec "$@"