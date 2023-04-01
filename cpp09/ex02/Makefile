NAME = PmergeMe
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -O3

SRCS = main.cpp \
       PmergeMe.cpp \
	   PmergeBenchmark.cpp \
	   PmergeVector.cpp
OBJS = $(SRCS:.cpp=.o)

RM = rm -fr

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $^ -o $@

clean:
	$(RM) $(OBJS) 
fclean: clean
	$(RM) $(NAME)
	
re: fclean all

debug: CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -g3 -fsanitize=address
debug: all

.PHONY: all clean fclean re
