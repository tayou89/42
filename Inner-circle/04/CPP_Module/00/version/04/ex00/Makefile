NAME = megaphone
GPP = g++
GPPFLAGS = -Wall -Wextra -Werror -std=c++98
RM = rm
RMFLAGS = -rf
FILE_NAME = megaphone
SOURCE_FILE = $(addsuffix .cpp, $(FILE_NAME))
OBJECT_FILE = $(addsuffix .o, $(FILE_NAME))

all : $(NAME)

clean : 
	$(RM) $(RMFLAGS) $(OBJECT_FILE)

fclean : clean
	$(RM) $(RMFLAGS) $(NAME)

re : fclean all

$(NAME) : $(OBJECT_FILE)
	$(GPP) $(GPPFLAGS) -o $(NAME) $^
	
%.o : %.cpp
	$(GPP) $(GPPFLAGS) -o $@ -c $< 

.PHONY : all clean fclean re libft bonus
