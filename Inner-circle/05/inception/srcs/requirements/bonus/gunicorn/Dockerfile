FROM debian:11.9

COPY tools/test.py /test.py
COPY entrypoint.sh /entrypoint.sh

RUN apt update && apt upgrade -y && \
	apt install python3 python3-pip -y && \
	pip install gunicorn flask  && \
	mkdir -p /var/www/gunicorn && \
	chmod +x /entrypoint.sh

EXPOSE 8000

WORKDIR /var/www/gunicorn

ENTRYPOINT ["/entrypoint.sh"]

CMD ["gunicorn", "--bind", "0.0.0.0:8000", "test:app"]
