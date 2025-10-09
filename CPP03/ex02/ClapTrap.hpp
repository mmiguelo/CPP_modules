#pragma once
#include <iostream>

#define RST		"\033[0m"
#define R		"\033[31m"
#define G		"\033[32m"

class ClapTrap
{
	protected:
		std::string	_name;
		unsigned int	_hitPoints;
		unsigned int	_energyPoints;
		unsigned int	_attackDamage;
	public:
		// orthodox canonical form:
		ClapTrap();
		ClapTrap(const std::string name);
		ClapTrap(const ClapTrap &src);
		ClapTrap& operator= (const ClapTrap &src);
		~ClapTrap();

		// methods:
		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
};
