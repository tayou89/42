NAME = so_long
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
	  check_map_is_rectangular check_map_surrounded_by_wall\
	  check_map_component check_map_has_valid_path \
	  check_accessibility \
	  get_array_map get_linked_list_map \
	  make_game \
	  make_initial_game_setting get_mlx_win_ptr make_map \
	  get_component_image_address put_image_to_map \
	  control_player \
	  move_by_direction move_by_component \
	  control_node \
	  utils \
	  finish_game_after_free free_functions
BONUS_FILE = so_long \
			check_map_extension \
			check_map_validation \
			check_map_is_rectangular check_map_surrounded_by_wall \
			check_map_component check_map_has_valid_path \
			check_accessibility \
			get_array_map get_linked_list_map \
			make_game \
			make_initial_game_setting \
			get_mlx_win_ptr make_map get_player_enemy_location \
			get_component_image_address put_image_to_map \
			control_player \
			move_by_direction move_by_component set_sprite_image \
			make_enemy_animation \
			control_node \
			utils \
			finish_game_after_free free_functions

SRC = $(addsuffix .c, $(SRC_FILE))
SRC_BONUS = $(addprefix bonus/, $(addsuffix _bonus.c, $(BONUS_FILE)))
OBJ = $(addsuffix .o, $(SRC_FILE))
OBJ_BONUS = $(addprefix bonus/, $(addsuffix _bonus.o, $(BONUS_FILE)))

ifdef WITH_BONUS
	OBJ_FILE = $(OBJ_BONUS)
else
	OBJ_FILE = $(OBJ)
endif

all : $(NAME)

clean : 
	make -C $(MLX_DIR) clean
	make -C $(LIBFT_DIR) clean
	$(RM) $(RMFLAGS) $(OBJ) $(OBJ_BONUS) 

fclean : clean
	make -C $(LIBFT_DIR) fclean
	$(RM) $(RMFLAGS) $(NAME)

re : fclean all

bonus :
	make WITH_BONUS=1

$(NAME) : $(MLX) $(LIBFT) $(OBJ_FILE)
	$(CC) $(CCFLAGS) -L./mlx -lmlx -framework OpenGL -framework AppKit -o $(NAME) $^ -g3 -fsanitize=address

$(MLX) :
	make -C $(MLX_DIR) all 

$(LIBFT) : 
	make bonus -C $(LIBFT_DIR) all
			   
%.o : %.c
	$(CC) $(CCFLAGS) -I./mlx -o $@ -c $<

.PHONY : all clean fclean re libft bonus
