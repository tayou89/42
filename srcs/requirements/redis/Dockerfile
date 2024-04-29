FROM debian:12.5

RUN apt update -y && apt upgrade -y && apt install aptitude -y && \
	apt install redis-server -y

CMD ["redis-server", "--protected-mode", "no"]
