#!/bin/sh

if [ ! -d /var/run/mysqld ]; then
	mkdir -p /var/run/mysqld
fi

if [ ! -d /var/log/mysql ]; then
	mkdir -p /var/log/mysql
	touch /var/log/mysql/mysql.log
	touch /var/log/mysql/error.log
fi

chown -R mysql:mysql /var/run/mysqld /var/lib/mysql /var/log/mysql
chmod 777 /var/run/mysqld /var/log/mysql


echo "Making database initializing file..."
cat << EOF > /tmp/init_database.sql 

FLUSH PRIVILEGES;
SET PASSWORD FOR '${DATABASE_ROOT}'@'${DATABASE_ROOT_HOST}' = PASSWORD('$DATABASE_ROOT_PASSWORD');
CREATE DATABASE ${DATABASE_NAME};
CREATE USER '${DATABASE_USER}'@'${DATABASE_USER_HOST}' IDENTIFIED BY '${DATABASE_USER_PASSWORD}';
GRANT ALL PRIVILEGES ON ${DATABASE_NAME}.* TO '${DATABASE_USER}'@'${DATABASE_USER_HOST}';
FLUSH PRIVILEGES;

EOF

if [ ! -d /var/lib/mysql/mysql ]; then
	echo  "Executing mysql_install_db..."
	mysql_install_db --user=mysql --ldir=/var/lib/mysql
fi

echo  "Executing /mysqld 1..."
/usr/sbin/mysqld --user=mysql --bootstrap < /tmp/init_database.sql

echo  "Executing /mysqld 2..."
exec /usr/sbin/mysqld --user=mysql --console
