FROM debian:11.9

COPY entrypoint.sh /entrypoint.sh

RUN apt update && apt upgrade -y && apt install aptitude -y && \
	aptitude install mariadb-server mariadb-client -y && \
	chmod +x /entrypoint.sh

EXPOSE	3306

ENTRYPOINT ["/entrypoint.sh"]
