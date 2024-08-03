FROM debian:11.9

COPY entrypoint.sh /entrypoint.sh

RUN apt update -y && \
	apt install exim4 exim4-config iproute2 -y && \
	usermod -u 1000 www-data && groupmod -g 1000 www-data && \
	chmod +x /entrypoint.sh

COPY conf/exim4.conf.template /etc/exim4/exim4.conf.template
COPY conf/update-exim4.conf.conf /etc/exim4/update-exim4.conf.conf

EXPOSE 25

ENTRYPOINT ["/entrypoint.sh"]

CMD ["exim", "-bdf"]
