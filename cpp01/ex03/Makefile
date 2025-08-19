NAME := war
CXX := c++
CXXFLAGS := -Wall -Werror -Wextra -std=c++98
INC := Weapon.hpp HumanA.hpp HumanB.hpp
SRC := Weapon.cpp HumanA.cpp HumanB.cpp main.cpp
OBJ := $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(INC) $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

%.o:%.cpp $(INC)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
