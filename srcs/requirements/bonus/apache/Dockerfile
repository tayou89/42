FROM debian:11.9

COPY entrypoint.sh /entrypoint.sh

RUN apt-get update -y && \ 
	apt-get install -y \
	apache2  python3 python3-pip \
	libapache2-mod-wsgi-py3 cpanminus gettext-base && \
	chmod +x /entrypoint.sh

COPY conf/apache2.conf 				/etc/apache2/apache2.conf
COPY conf/wordpress.conf.template	/etc/apache2/sites-enabled/wordpress.conf.template
COPY conf/ports.conf 				/etc/apache2/ports.conf
COPY web-document 					/web-document

ENTRYPOINT ["/entrypoint.sh"]

EXPOSE 8443

CMD ["apache2ctl", "-D", "FOREGROUND"]
