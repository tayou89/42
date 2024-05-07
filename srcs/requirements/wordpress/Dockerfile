FROM debian:11.9

COPY entrypoint.sh /entrypoint.sh

RUN	apt update -y && apt upgrade -y && apt install aptitude -y && \
	aptitude install php php-curl php-fpm php-bcmath php-gd php-soap -y && \
	aptitude install php-mbstring php-mysqlnd php-xml php-intl php-zip php-mysqli -y && \
	usermod -u 1000 www-data && groupmod -g 1000 www-data && \
	mkdir -p /run/php && \
	chmod +x /entrypoint.sh

WORKDIR	/var/www

RUN	aptitude install wget unzip -y && \	
	wget https://wordpress.org/latest.zip && \
	unzip latest.zip && rm latest.zip

WORKDIR /var/www/wordpress

RUN	find . -type d -exec chmod 755 {} \; && \
	find . -type f -exec chmod 644 {} \;

EXPOSE 9000

ENTRYPOINT ["/entrypoint.sh"]

CMD	["php-fpm7.4", "-F"]
