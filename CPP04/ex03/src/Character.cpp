#include "../Character.hpp"
#include "../ICharacter.hpp"

Character::Character() : name("Default")
{
	for (int i = 0; i < 4; i++)
		inventory[i] = NULL;
	for (int i = 0; i < 100; i++)
		droped[i] = NULL;
	std::cout << G << "Character: Default constructor called" << RST << std::endl;
}

Character::Character(std::string const & name) : name(name)
{
	for (int i = 0; i < 4; i++)
		inventory[i] = NULL;
	for (int i = 0; i < 100; i++)
		droped[i] = NULL;
	std::cout << G << "Character: Parameterized constructor called" << RST << std::endl;
}