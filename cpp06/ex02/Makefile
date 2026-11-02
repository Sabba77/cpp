NAME = base

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = Base.cpp BaseFunction.cpp A.cpp B.cpp C.cpp main.cpp 
OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
