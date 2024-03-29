NAME = so_long
CC = gcc
CCFLAGS = -Wall -Wextra -Werror
RM = rm
RMFLAGS = -rf
LIBFT = ./libft/libft.a
LIBFT_DIR = ./libft
SRC = so_long.c \
	  free_2d_string_array.c
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
	$(CC) $(CCFLAGS) -L./mlx -lmlx -framework OpenGL -framework AppKit -o $(NAME) $^

$(LIBFT) : 
	make bonus -C $(LIBFT_DIR) all
			   
%.o : %.c
	$(CC) $(CCFLAGS) -I./mlx -o $@ -c $<

.PHONY : all clean fclean re libft

