FROM debian:12.5

COPY entrypoint.sh /entrypoint.sh

RUN	apt update -y && apt upgrade -y && apt install aptitude -y && \
	aptitude install php php-curl php-fpm php-bcmath php-gd php-soap -y && \
	aptitude install php-mbstring php-mysqlnd php-xml php-intl php-zip php-mysqli -y && \
	chmod +x /entrypoint.sh

WORKDIR	/var/www/html

RUN	aptitude install wget unzip -y && \	
	wget https://wordpress.org/latest.zip && \
	unzip latest.zip && rm latest.zip

WORKDIR /var/www/html/wordpress

RUN	find . -type d -exec chmod 755 {} \; && \
	find . -type f -exec chmod 644 {} \;

COPY ./php/8.2/fpm/php.ini /etc/php/8.2/fpm/php.ini

CMD	["php-fpm8.2", "-F"]

EXPOSE 9000

ENTRYPOINT ["/entrypoint.sh"]

