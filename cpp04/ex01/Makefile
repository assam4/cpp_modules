NAME := a.out
CXX := c++
CXXFLAGS := -Wall -Wextra -Werror -std=c++98

INC := Animal.hpp Dog.hpp Cat.hpp Brain.hpp
SRC := Animal.cpp Dog.cpp Cat.cpp main.cpp Brain.cpp
OBJ := $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ) $(SRC)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

%.o:%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all 

.PHONY: all clean fclean re
