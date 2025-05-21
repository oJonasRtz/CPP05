
NAME = bureaucrat

CC = c++
FLAGS = -g3 -Wall -Werror -Wextra -std=c++98

INCLUDE = includes
SRC =	Bureaucrat.cpp\
		main.cpp
SRCS = $(addprefix src/, $(SRC))
OBJS = $(SRCS:.cpp=.o)

RM = rm -f

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(FLAGS) -I$(INCLUDE) -o $(NAME) $(OBJS)

src/%.o: src/%.cpp
	@echo "\033[1;32mCompiling	->	$<\033[0m"
	@$(CC) $(FLAGS) -I$(INCLUDE) -c $< -o $@

run: all
	@valgrind ./$(NAME)

test: all
	@valgrind ./$(NAME) 1
	@valgrind ./$(NAME) 2


clean:
	@echo "\033[1;32m===========================================\033[0m"
	@echo "\033[1;32m		OBJECTS REMOVED						\033[0m"
	@echo "\033[1;32m===========================================\033[0m"
	@$(RM) $(OBJS)

fclean: clean
	@echo "\033[1;32m===========================================\033[0m"
	@echo "\033[1;32m		$(NAME) REMOVED						\033[0m"
	@echo "\033[1;32m===========================================\033[0m"	
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re run