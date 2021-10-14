NAME = megaphone

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = megaphone.cpp

OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

test: $(NAME)
	@echo
	./$(NAME) "shhhhh... I think the students are asleep..."
	@echo
	./$(NAME) Damnit " ! " "Sorry students, I thought this thing was off."
	@echo
	./$(NAME)
	@echo

.PHONY: all clean fclean re test
