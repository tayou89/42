FROM debian:12.5

RUN apt update -y && apt upgrade -y && apt install aptitude -y && \
	aptitude install postfix mailutils -y

EXPOSE 25

CMD ["postfix", "start-fg"]
