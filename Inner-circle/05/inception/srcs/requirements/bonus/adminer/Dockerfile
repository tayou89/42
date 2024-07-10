FROM debian:11.9

COPY entrypoint.sh /entrypoint.sh

RUN apt update -y && apt upgrade -y && apt install aptitude -y && \
	aptitude install wget php php-fpm php-mysqli php-mysqlnd php-xml -y && \
	chmod +x /entrypoint.sh && \
	usermod -u 1000 www-data && groupmod -g 1000 www-data

COPY conf/php.ini 				/etc/php/7.4/fpm/php.ini
COPY conf/php-fpm.conf			/etc/php/7.4/fpm/php-fpm.conf
COPY conf/www.conf 				/etc/php/7.4/fpm/pool.d/www.conf
COPY web-document/adminer.php	/adminer.php

EXPOSE 9001

ENTRYPOINT ["/entrypoint.sh"]

CMD ["php-fpm7.4", "-F"]
