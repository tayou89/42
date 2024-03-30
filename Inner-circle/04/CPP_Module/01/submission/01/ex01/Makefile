NAME = Zombie
CPP = c++
CPPFLAGS = -Wall -Wextra -Werror -std=c++98
RM = rm
RMFLAGS = -rf
FILE_NAME = main \
			Zombie \
			zombieHorde

SOURCE_FILE = $(addsuffix .cpp, $(FILE_NAME))
OBJECT_FILE = $(addsuffix .o, $(FILE_NAME))

all : $(NAME)

clean : 
	$(RM) $(RMFLAGS) $(OBJECT_FILE)

fclean : clean
	$(RM) $(RMFLAGS) $(NAME)

re : fclean all

$(NAME) : $(OBJECT_FILE)
	$(CPP) $(CPPFLAGS) -o $(NAME) $^
	
%.o : %.cpp
	$(CPP) $(CPPFLAGS) -o $@ -c $< 

.PHONY : all clean fclean re
