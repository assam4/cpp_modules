NAME:= easyfind
CXX:= c++
CXXFLAGS := -Wall -Wextra -Werror

INC:= easyfind.tpp easyfind.hpp
SRC:= main.cpp
OBJ:= $(SRC:.cpp=.o)

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
