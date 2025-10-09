#pragma once
#include <iostream>
#include <string>
#include "ClapTrap.hpp"

#define RST		"\033[0m"
#define R		"\033[31m"
#define G		"\033[32m"

class ScavTrap : public ClapTrap
{
	public:
		// orthodox canonical form:
		ScavTrap();
		ScavTrap(const std::string name);
		ScavTrap(const ScavTrap &src);
		ScavTrap& operator= (const ScavTrap &src);
		~ScavTrap();

		// methods:
		void attack(const std::string& target);
		void guardGate();
};

