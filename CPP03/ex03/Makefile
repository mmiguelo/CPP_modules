NAME = DiamondTrap

SRC 	 = src/main.cpp
SRC		+= src/ScavTrap.cpp
SRC		+= src/ClapTrap.cpp
SRC		+= src/FragTrap.cpp
SRC		+= src/DiamondTrap.cpp

CXX = c++
CXXFLAGS = -Wall -Werror -Wextra -std=c++98

OBJ = $(SRC:.cpp=.o)

all: $(NAME)
$(NAME): $(OBJ)
	@$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJ)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all