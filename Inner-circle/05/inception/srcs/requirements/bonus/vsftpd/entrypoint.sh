#!/bin/sh

chown -R www-data:www-data /var/www/wordpress
chmod -R 755 /var/www/wordpress
chown root:root /etc/vsftpd/vsftpd.conf


if ! id "${FTP_USER}" > /dev/null 2>&1; then
	echo "User ${FTP_USER} doesn't exist!"
	useradd -m -s /bin/bash ${FTP_USER}
	usermod -d /var/www/wordpress ${FTP_USER}
else
	echo "User ${FTP_USER} already exist!"
	chsh -s /bin/bash ${FTP_USER}
	usermod -s /bin/bash ${FTP_USER}
	usermod -d /var/www/wordpress ${FTP_USER}
fi

echo "${FTP_USER}:${FTP_USER_PASSWORD}" | chpasswd


if ! grep -q "^${FTP_USER}$" /etc/vsftpd/user_list; then
	echo "${FTP_USER}" >> /etc/vsftpd/user_list
fi

exec "$@"
