#pragma once

#include "AMateria.hpp"
#include "ICharacter.hpp"
#include <iostream>
#include <string>

#define R		"\033[0;31m" //RED
#define G		"\033[0;32m" //GREEN
#define Y		"\033[0;33m" //YELLOW
#define B		"\033[0;34m" //BLUE
#define RST		"\033[0m"   //RESET

class Character : public ICharacter
{
	private:
		std::string _name;
		AMateria* inventory[4];
		AMateria* droped[100];
		int _droped_count;

	public:
		Character();
		Character(std::string const & name);
		Character(const Character &other);
		Character &operator=(const Character &other);
		~Character();

		std::string const & getName() const;
		void equip(AMateria* m);
		void unequip(int index);
		void use(int index, ICharacter& target);
};
