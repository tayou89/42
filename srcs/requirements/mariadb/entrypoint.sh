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
SET PASSWORD FOR '${DATABASE_ROOT}'@'localhost' = PASSWORD('$DATABASE_ROOT_PASSWORD');
CREATE DATABASE IF NOT EXISTS ${DATABASE_NAME};
CREATE USER '${DATABASE_USER}'@'%' IDENTIFIED BY '${DATABASE_USER_PASSWORD}';
GRANT ALL PRIVILEGES ON ${DATABASE_NAME}.* TO '${DATABASE_USER}'@'%';
FLUSH PRIVILEGES;

EOF

if [ ! -d /var/lib/mysql/mysql ]; then
	echo  "Executing mysql_install_db..."
	mysql_install_db --user=mysql --ldir=/var/lib/mysql
fi

/usr/sbin/mysqld --user=mysql --bootstrap < /tmp/init_database.sql

echo  "Executing /mysqld..."
exec /usr/sbin/mysqld --user=mysql --console
