FROM debian:11.9

COPY entrypoint.sh /entrypoint.sh

RUN apt update -y && \
	apt install exim4 exim4-config iproute2 -y && \
	usermod -u 1000 www-data && groupmod -g 1000 www-data && \
	chmod +x /entrypoint.sh

EXPOSE 25

ENTRYPOINT ["/entrypoint.sh"]
