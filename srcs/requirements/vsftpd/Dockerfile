FROM debian:12.5

COPY entrypoint.sh	/entrypoint.sh

RUN apt update && apt upgrade && apt install aptitude -y && \
	aptitude install vsftpd dumb-init -y && \
	mkdir -p /etc/vsftpd && mv /etc/vsftpd.conf /etc/vsftpd && \
	mkdir -p /var/run/vsftpd/empty && \
	usermod -u 1000 www-data && groupmod -g 1000 www-data && \
	chmod +x /entrypoint.sh && \
	chmod +x /usr/bin/dumb-init

EXPOSE 21

ENTRYPOINT ["/entrypoint.sh"]

CMD ["vsftpd", "/etc/vsftpd/vsftpd.conf"]
