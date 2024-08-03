FROM alpine:3.19

COPY entrypoint.sh /entrypoint.sh

RUN apk add --no-cache nginx curl shadow busybox-extras gettext && \
	groupmod -g 1000 www-data && usermod -u 1000 -g www-data nginx && \
	chmod +x /entrypoint.sh

COPY conf/nginx.conf /etc/nginx/nginx.conf
COPY conf/wordpress.conf.template /etc/nginx/http.d/wordpress.conf.template

EXPOSE 443

ENTRYPOINT ["/entrypoint.sh"]

CMD ["nginx", "-g", "daemon off;"]
