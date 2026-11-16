NAME = btc

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

# make        --> subject main (main.cpp)
# make test   --> same binary name, but built from mainTest.cpp
ifdef TEST
SRCS = mainTest.cpp BitcoinExchange.cpp
else
SRCS = main.cpp BitcoinExchange.cpp
endif
OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

test: fclean
	$(MAKE) TEST=1 all

clean:
	rm -f main.o mainTest.o BitcoinExchange.o

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re test