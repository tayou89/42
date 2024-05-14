COMPOSE_FILE = srcs/docker-compose.yml

all: dir build up

restart: down up

dir:
	mkdir -p ~/data
	mkdir -p ~/data/mariadb
	mkdir -p ~/data/wordpress
	mkdir -p ~/data/adminer
	mkdir -p ~/data/apache
	cp -rf ~/ssl ~/data

build:
	docker compose -f $(COMPOSE_FILE) build

up:
	docker compose -f $(COMPOSE_FILE) up

down:
	docker compose -f $(COMPOSE_FILE) down

logs:
	docker compose -f $(COMPOSE_FILE) logs

clean:
	docker compose -f $(COMPOSE_FILE) down --rmi all -v --remove-orphans

fclean: clean
	docker system prune -a --force

re: fclean all

status:
	docker compose -f $(COMPOSE_FILE) ps

.PHONY: all build up down logs clean rebuild status
