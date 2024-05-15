FROM debian:11.9

RUN apt update -y && apt upgrade -y && apt install aptitude -y && \
	apt install redis-server -y

COPY conf/redis.conf /etc/redis/redis.conf

CMD ["redis-server", "--protected-mode", "no"]
