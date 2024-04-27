FROM debian:12.5

RUN apt update && apt upgrade && apt install aptitude -y && \
	apt install redis-server -y

CMD ["redis-server", "--protected-mode", "no"]