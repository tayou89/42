FROM debian:11.9

COPY entrypoint.sh /entrypoint.sh

RUN apt update -y && apt upgrade -y && apt install aptitude -y && \
	aptitude install wget php php-fpm php-mysqli php-mysqlnd php-xml -y && \
	chmod +x /entrypoint.sh && \
	usermod -u 1000 www-data && groupmod -g 1000 www-data && \
	mkdir -p /var/www/adminer /usr/log && touch /usr/log/www.access.log && \
	wget "http://www.adminer.org/latest.php" -O /var/www/adminer/adminer.php && \
	mkdir -p /run/php

EXPOSE 9001

ENTRYPOINT ["/entrypoint.sh"]

CMD ["php-fpm7.4", "-F"]
