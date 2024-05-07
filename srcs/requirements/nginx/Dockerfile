FROM alpine:3.18

COPY entrypoint.sh /entrypoint.sh

RUN apk add --no-cache nginx bash vim curl shadow busybox-extras gettext && \
	groupmod -g 1000 www-data && usermod -u 1000 -g www-data nginx && \
	chmod +x /entrypoint.sh

EXPOSE 443

ENTRYPOINT ["/entrypoint.sh"]

CMD ["nginx", "-g", "daemon off;"]
