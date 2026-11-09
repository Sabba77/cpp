NAME = array
SUB_NAME = array_sub

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -I.

SRCS = main.cpp
OBJS = $(SRCS:.cpp=.o)

SUB_SRCS = sub_main.cpp		# change with subject main to test
SUB_OBJS = $(SUB_SRCS:.cpp=.o)

all: $(NAME)

sub: $(SUB_NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

$(SUB_NAME): $(SUB_OBJS)
	$(CXX) $(CXXFLAGS) -o $(SUB_NAME) $(SUB_OBJS)

%.o: %.cpp Array.hpp Array.tpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(SUB_OBJS)

fclean: clean
	rm -f $(NAME) $(SUB_NAME)

re: fclean all

.PHONY: all sub clean fclean re