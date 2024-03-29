# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/12 23:45:30 by tayou             #+#    #+#              #
#    Updated: 2023/05/14 19:11:17 by tayou            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
NAME_BONUS = so_long_bonus
CC = gcc
CCFLAGS = -Wall -Wextra -Werror
RM = rm
RMFLAGS = -rf
LIBFT = ./libft/libft.a
LIBFT_DIR = ./libft
MLX = ./mlx/libmlx.a
MLX_DIR = ./mlx
SRC_FILE = so_long \
	  check_map_extension \
	  check_map_validation \
	  check_map_is_rectangular check_map_surrounded_by_wall \
	  check_map_component check_map_has_valid_path \
	  check_accessibility \
	  get_array_map get_linked_list_map \
	  make_game \
	  make_initial_game_setting get_image_address \
	  when_key_is_pressed when_click_x_button_on_window \
	  make_player_move_to_target \
	  control_node \
	  utils_1 utils_2 \
	  finish_game_after_free free_functions handle_error
BONUS_FILE = so_long \
			check_map_extension \
			check_map_validation \
			check_map_is_rectangular check_map_surrounded_by_wall \
			check_map_component check_map_has_valid_path \
			check_accessibility \
			get_array_map get_linked_list_map \
			make_game \
			make_initial_game_setting \
			get_image_address get_player_enemy_location \
			when_key_is_pressed when_click_x_button_on_window \
			when_key_not_pressed \
			make_enemy_on_guard turn_enemy_to_direction \
			check_every_enemy_if_find_invader move_enemy_to_direction \
			make_player_move_to_target \
			control_node \
			utils_1 utils_2\
			finish_game_after_free free_functions handle_error

SRC = $(addsuffix .c, $(SRC_FILE))
SRC_BONUS = $(addprefix bonus/, $(addsuffix _bonus.c, $(BONUS_FILE)))
OBJ = $(addsuffix .o, $(SRC_FILE))
OBJ_BONUS = $(addprefix bonus/, $(addsuffix _bonus.o, $(BONUS_FILE)))

all : $(NAME)

clean : 
	make -C $(MLX_DIR) clean
	make -C $(LIBFT_DIR) clean
	$(RM) $(RMFLAGS) $(OBJ) $(OBJ_BONUS) 

fclean : clean
	make -C $(LIBFT_DIR) fclean
	$(RM) $(RMFLAGS) $(NAME) $(NAME_BONUS)

re : fclean all

bonus : $(NAME_BONUS)

$(NAME) : $(MLX) $(LIBFT) $(OBJ)
	$(CC) $(CCFLAGS) -L./mlx -lmlx -framework OpenGL -framework AppKit -o $(NAME) $^

$(NAME_BONUS) : $(MLX) $(LIBFT) $(OBJ_BONUS)
	$(CC) $(CCFLAGS) -L./mlx -lmlx -framework OpenGL -framework AppKit -o $(NAME_BONUS) $^

$(MLX) :
	make -C $(MLX_DIR) all 

$(LIBFT) : 
	make bonus -C $(LIBFT_DIR) all
			   
%.o : %.c
	$(CC) $(CCFLAGS) -I./mlx -o $@ -c $<

.PHONY : all clean fclean re libft bonus
