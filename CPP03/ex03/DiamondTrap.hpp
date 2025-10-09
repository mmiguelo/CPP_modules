#pragma once
#include <iostream>
#include <string>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

#define RST		"\033[0m"
#define R		"\033[31m"
#define G		"\033[32m"

class DiamondTrap : public ScavTrap, public FragTrap
{
	private:
		std::string	_name;
	public:
		// orthodox canonical form:
		DiamondTrap();
		DiamondTrap(const std::string name);
		DiamondTrap(const DiamondTrap &src);
		DiamondTrap& operator= (const DiamondTrap &src);
		~DiamondTrap();

		//methods:
		void	whoAmI();
		void	attack(const std::string &target);
};
