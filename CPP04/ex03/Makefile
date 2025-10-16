NAME = materia

SRC		 = src/AMateria.cpp
SRC		+= src/Character.cpp
SRC		+= src/Cure.cpp
SRC		+= src/Ice.cpp
SRC		+= src/ICharacter.cpp
SRC		+= src/IMateriaSource.cpp
SRC		+= src/main.cpp
SRC		+= src/MateriaSource.cpp

CXX = c++
CXXFLAGS = -Wall -Werror -Wextra -std=c++98
VAL = valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes

OBJ = $(SRC:.cpp=.o)

all: $(NAME)
$(NAME): $(OBJ)
	@$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJ)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

val: all
	@$(VAL) ./$(NAME)

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all