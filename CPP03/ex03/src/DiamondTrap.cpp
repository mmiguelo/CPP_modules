#include "../DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap("Diamond_clap_name"), ScavTrap(), FragTrap()
{
	this->_name = "Default";
	this->_hitPoints = FragTrap::_hitPoints;
	this->_energyPoints = ScavTrap::_energyPoints;
	this->_attackDamage = FragTrap::_attackDamage;
	std::cout << G << "DiamondTrap " << this->_name << " created with default constructor" << RST << std::endl;
}

DiamondTrap::DiamondTrap(const std::string name) : ClapTrap(name + "_clap_name"), ScavTrap(), FragTrap()
{
	this->_name = name;
	this->_hitPoints = FragTrap::_hitPoints;
	this->_energyPoints = ScavTrap::_energyPoints;
	this->_attackDamage = FragTrap::_attackDamage;
	std::cout << G << "DiamondTrap " << this->_name << " created with parameterized constructor" << RST << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &src) : ClapTrap(src), ScavTrap(src), FragTrap(src)
{
	*this = src;
	std::cout << G << "DiamondTrap " << this->_name << " created with copy constructor" << RST << std::endl;
}

DiamondTrap& DiamondTrap::operator= (const DiamondTrap &src)
{
	if (this != &src)
	{
		this->_name = src._name;
		this->_hitPoints = src._hitPoints;
		this->_energyPoints = src._energyPoints;
		this->_attackDamage = src._attackDamage;
	}
	std::cout << G << "DiamondTrap " << this->_name << " created with copy assignment operator" << RST << std::endl;
	return (*this);
}

DiamondTrap::~DiamondTrap()
{
	std::cout << R << "DiamondTrap " << this->_name << " destroyed" << RST << std::endl;
}

void	DiamondTrap::attack(const std::string &target)
{
	ScavTrap::attack(target);
}

void	DiamondTrap::whoAmI()
{
	std::cout << G << "DiamondTrap name: " << this->_name << ", ClapTrap name: " << ClapTrap::_name << RST << std::endl;
}
