NAME := RPN
CXX := c++
CXXFLAGS := -Wall -Wextra -Werror -std=c++98

INC := RPN.hpp
SRC := RPN.cpp main.cpp
OBJ := $(SRC:.cpp=.o)

all : $(NAME)

$(NAME) : $(INC) $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

%.o : %.cpp $(INC)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean: 
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re : fclean all

.PHONY: all clean fclean re
