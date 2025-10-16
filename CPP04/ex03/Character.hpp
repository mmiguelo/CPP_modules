#pragma once

#include "AMateria.hpp"
#include "ICharacter.hpp"
#include <iostream>
#include <string>

class Character : public ICharacter
{
	private:
		std::string name;

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
