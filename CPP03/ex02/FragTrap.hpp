#pragma once
#include <iostream>
#include <string>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

#define RST		"\033[0m"
#define R		"\033[31m"
#define G		"\033[32m"

class FragTrap : public ClapTrap
{
	public:
		// orthodox canonical form:
		FragTrap();
		FragTrap(const std::string name);
		FragTrap(const FragTrap &src);
		FragTrap& operator= (const FragTrap &src);
		~FragTrap();

		// methods:
		void highFivesGuys(void);
};

