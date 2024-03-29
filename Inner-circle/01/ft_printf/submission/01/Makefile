NAME = libftprintf.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm
RMFLAGS = -rf
AR = ar
ARFLAGS = -rcs
LIBFT = ./libft/libft.a
LIBFT_DIR = ./libft
SRCS = ft_printf.c \
	   ft_various.c \
	   ft_print_character.c ft_print_string.c \
	   ft_print_address.c \
	   ft_print_decimal.c ft_print_unsigned.c ft_print_hexa.c \
	   ft_print_percent.c
		
OBJS = $(SRCS:.c=.o)

all : 
	make $(NAME) 

clean : 
	make -C $(LIBFT_DIR) clean
	$(RM) $(RMFLAGS) $(OBJS)

fclean : clean
	make -C $(LIBFT_DIR) fclean
	$(RM) $(RMFLAGS) $(NAME)

re : fclean all

$(NAME) : $(LIBFT) $(OBJS)
	cp $(LIBFT) $(NAME)
	$(AR) $(ARFLAGS) $@ $^

$(LIBFT) :
	make -C $(LIBFT_DIR) all

%.o : %.c
	$(CC) $(CFLAGS) -o $@ -c $<

.PHONY: all clean fclean re bonus libft
