NAME := a.out
CXX := c++
CXXFLAGS := -Wall -Wextra -Werror -std=c++98

INC := Bureaucrat.hpp Form.hpp
SRC := Bureaucrat.cpp Form.cpp main.cpp
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
