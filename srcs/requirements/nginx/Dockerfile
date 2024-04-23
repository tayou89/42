FROM alpine:3.17

COPY entrypoint.sh /entrypoint.sh

RUN apk add --no-cache nginx bash vim curl && \
	chmod +x /entrypoint.sh

EXPOSE 443

CMD ["nginx", "-g", "daemon off;"]

ENTRYPOINT ["/entrypoint.sh"]
