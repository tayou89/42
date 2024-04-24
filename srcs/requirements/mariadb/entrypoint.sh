#!/bin/sh

#service mariadb start
echo "Starting MariaDB with settings:"
echo "Database: ${DATABASE_NAME}"
echo "User: ${DATABASE_USER}@${DATABASE_HOST}"

mysql -e "CREATE DATABASE ${DATABASE_NAME};"
mysql -e "CREATE USER ${DATABASE_USER}@${DATABASE_HOST} IDENTIFIED BY '${DATABASE_PASSWORD}';"
mysql -e "GRANT ALL PRIVILEGES ON ${DATABASE_NAME}.* TO ${DATABASE_USER}@${DATABASE_HOST};"
mysql -e "FLUSH PRIVILEGES;"

exec "$@"