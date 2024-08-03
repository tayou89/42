FROM debian:11.9

COPY entrypoint.sh /entrypoint.sh

RUN	apt update -y && apt upgrade -y && apt install aptitude -y && \
	aptitude install php php-curl php-fpm php-bcmath php-gd php-soap -y && \
	aptitude install php-mbstring php-mysqlnd php-xml php-intl php-zip php-mysqli -y && \
	aptitude install wget unzip -y && \
	usermod -u 1000 www-data && groupmod -g 1000 www-data && \
	mkdir -p /run/php && \
	chmod +x /entrypoint.sh

COPY conf/php.ini 				/etc/php/7.4/fpm/php.ini
COPY conf/php-fpm.conf			/etc/php/7.4/fpm/php-fpm.conf
COPY conf/www.conf 				/etc/php/7.4/fpm/pool.d/www.conf
COPY web-document/wp-config.php	/wp-config.php

WORKDIR	/var/www

EXPOSE 9000

ENTRYPOINT ["/entrypoint.sh"]

CMD	["php-fpm7.4", "-F"]
