#!/bin/sh

if [ ! -f /var/www/wordpress/wp-config.php ]; then
		aptitude install wget unzip -y
		wget https://wordpress.org/latest.zip
		unzip latest.zip -d /var/www
		rm latest.zip 

		wget https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar
		chmod +x wp-cli.phar

		mv wp-cli.phar /usr/local/bin/wp 
		mv /wp-config.php /var/www/wordpress

fi

cd /var/www/wordpress

if ! wp core is-installed --allow-root; then
		echo "Installing WordPress..."
		wp core install --allow-root \
						--url="https://${SERVER_NAME}" \
						--title="${WORDPRESS_TITLE}" \
						--admin_user="${WORDPRESS_ADMIN}" \
						--admin_password="${WORDPRESS_ADMIN_PASSWORD}" \
						--admin_email="${WORDPRESS_ADMIN_EMAIL}"

		wp user create --allow-root ${WORDPRESS_USER} ${WORDPRESS_USER_EMAIL} \
					   --role=${WORDPRESS_USER_ROLE} --user_pass=${WORDPRESS_USER_PASSWORD} \

		wp plugin install redis-cache wp-mail-smtp manage-notification-emails --activate --allow-root
		wp redis enable --allow-root

else	
		echo "WordPress is already installed"
fi

find /var/www/wordpress -type d -exec chmod 755 {} \;
find /var/www/wordpress -type f -exec chmod 644 {} \;

chown -R www-data:www-data /var/www/wordpress
chown -R www-data:www-data /run/php
chmod -R 755 /var/www/wordpress

exec "$@"
