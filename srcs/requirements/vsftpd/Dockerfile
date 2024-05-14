FROM debian:11.9

COPY entrypoint.sh	/entrypoint.sh

RUN apt update && apt upgrade -y && apt install aptitude -y && \
	aptitude install vsftpd dumb-init -y && \
	mkdir -p /etc/vsftpd && mv /etc/vsftpd.conf /etc/vsftpd && \
	mkdir -p /var/run/vsftpd/empty && \
	usermod -u 1000 www-data && groupmod -g 1000 www-data && \
	chmod +x /entrypoint.sh && \
	chmod +x /usr/bin/dumb-init

COPY conf/vsftpd.conf /etc/vsftpd/vsftpd.conf

EXPOSE 21

ENTRYPOINT ["/entrypoint.sh"]

CMD ["vsftpd", "/etc/vsftpd/vsftpd.conf"]
