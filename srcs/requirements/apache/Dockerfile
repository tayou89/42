FROM debian:12.5

COPY entrypoint.sh /entrypoint.sh

RUN apt-get update -y && \ 
	apt-get install -y \
	apache2  python3 python3-pip \
	libapache2-mod-wsgi-py3 cpanminus gettext-base && \
	chmod +x /entrypoint.sh

ENTRYPOINT ["/entrypoint.sh"]

EXPOSE 8443

CMD ["apache2ctl", "-D", "FOREGROUND"]
#CMD ["tail", "-f", "/dev/null"]
