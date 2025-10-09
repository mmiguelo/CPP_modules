#include "../ClapTrap.hpp"

ClapTrap::ClapTrap() : _name("Default"), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << G << "ClapTrap " << this->_name << " Default constructor called" << RST << std::endl;
}

ClapTrap::ClapTrap(const std::string name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << G << "ClapTrap " << this->_name << " constructor called" << RST << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &src)
{
	std::cout << G << "ClapTrap " << this->_name << " Copy constructor called" << RST << std::endl;
	*this = src;
}

ClapTrap& ClapTrap::operator= (const ClapTrap &src)
{
	std::cout << G << "Copy assignment operator called" << RST << std::endl;
	if (this != &src)
	{
		this->_name = src._name;
		this->_hitPoints = src._hitPoints;
		this->_energyPoints = src._energyPoints;
		this->_attackDamage = src._attackDamage;
	}
	return *this;
}

ClapTrap::~ClapTrap()
{
	std::cout << R << "Destructor called" << RST << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
	if (this->_hitPoints == 0)
	{
		std::cout << "ClapTrap " << this->_name << " is bleeding dead on the ground thus cannot attack" << std::endl;
		return;
	}
	if (this->_energyPoints == 0)
	{
		std::cout << "ClapTrap " << this->_name << " is drained out of energy thus cannot attack" << std::endl;
		return;
	}
	else
	{
		std::cout << "ClapTrap " << this->_name << " attacks " << target << ", causing " << this->_attackDamage << " points of damage!" << std::endl;
		this->_energyPoints--;
	}
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_hitPoints == 0)
	{
		std::cout << R << "Pleeeeease, have mercy on this ClapTrap " << this->_name << ", cuz he is already dead!" << RST << std::endl;
		return;
	}
	if (amount >= this->_hitPoints)
	{
		this->_hitPoints = 0;
		std::cout << "ClapTrap " << this->_name << " takes " << amount << " points of damage and is now bleeding dead on the ground" << std::endl;
	}
	else
	{
		this->_hitPoints -= amount;
		std::cout << "ClapTrap " << this->_name << " takes " << amount << " points of damage and now has " << this->_hitPoints << " hit points left" << std::endl;
	}
}
void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_hitPoints == 0)
	{
		std::cout << "ClapTrap " << this->_name << " is bleeding dead on the ground thus cannot be repaired" << std::endl;
		return;
	}
	if (this->_energyPoints == 0)
	{
		std::cout << "ClapTrap " << this->_name << " is drained out of energy thus cannot be repaired" << std::endl;
		return;
	}
	else
	{
		this->_hitPoints += amount;
		this->_energyPoints--;
		std::cout << "ClapTrap " << this->_name << " drank a " << R << "red potion " << RST << "and is repaired by " << amount << " points and now has " << this->_hitPoints << " hit points" << std::endl;
	}
}
