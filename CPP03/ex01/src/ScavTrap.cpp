#include "../ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
	std::cout << G << "ScavTrap " << this->_name << " constructor called" << RST << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
	std::cout << G << "ScavTrap " << this->_name << " constructor called" << RST << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &src) : ClapTrap(src)
{
	*this = src;
	std::cout << G << "ScavTrap " << this->_name << " copy constructor called" << RST << std::endl;
}

ScavTrap& ScavTrap::operator= (const ScavTrap &src)
{
	if (this != &src)
	{
		this->_name = src._name;
		this->_hitPoints = src._hitPoints;
		this->_energyPoints = src._energyPoints;
		this->_attackDamage = src._attackDamage;
	}
	std::cout << G << "ScavTrap " << this->_name << " copy assignment operator called" << RST << std::endl;
	return *this;
}

ScavTrap::~ScavTrap()
{
	std::cout << R << "Destructor called" << RST << std::endl;
}

void	ScavTrap::attack(const std::string& target)
{
	if (this->_hitPoints == 0)
	{
		std::cout << "ScavTrap " << this->_name << " is bleeding dead on the ground thus cannot attack" << std::endl;
		return;
	}
	if (this->_energyPoints == 0)
	{
		std::cout << "ScavTrap " << this->_name << " is drained out of energy thus cannot attack" << std::endl;
		return;
	}
	else
	{
		std::cout << "ScavTrap " << this->_name << " attacks " << target << ", causing " << this->_attackDamage << " points of damage!" << std::endl;
		this->_energyPoints--;
	}
}

void	ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << this->_name << " is now in Gate keeper mode." << std::endl;
}
