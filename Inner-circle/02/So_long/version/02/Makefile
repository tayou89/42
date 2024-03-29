NAME = so_long
CC = gcc
CCFLAGS = -Wall -Wextra -Werror
RM = rm
RMFLAGS = -rf
LIBFT = ./libft/libft.a
LIBFT_DIR = ./libft
SRC = so_long.c \
	  check_map_extension.c \
	  check_map_validation.c \
	  check_map_is_rectangular.c check_map_surrounded_by_wall.c \
	  check_map_component.c check_map_has_valid_path.c \
	  get_map.c get_access_check_map.c \
	  control_node.c \
	  utils.c \
	  free_functions.c
OBJ = $(SRC:.c=.o)

all : $(NAME)

clean : 
	make -C $(LIBFT_DIR) clean
	$(RM) $(RMFLAGS) $(OBJ) 

fclean : clean
	make -C $(LIBFT_DIR) fclean
	$(RM) $(RMFLAGS) $(NAME)

re : fclean all

$(NAME) : $(LIBFT) $(OBJ)
	$(CC) $(CCFLAGS) -L./mlx -lmlx -framework OpenGL -framework AppKit -o $(NAME) $^ -g -fsanitize=address

$(LIBFT) : 
	make bonus -C $(LIBFT_DIR) all
			   
%.o : %.c
	$(CC) $(CCFLAGS) -I./mlx -o $@ -c $<

.PHONY : all clean fclean re libft

