#include "../FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
	std::cout << G << "FragTrap " << this->_name << " created with default constructor" << RST << std::endl;
}

FragTrap::FragTrap(const std::string name) : ClapTrap(name)
{
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
	std::cout << G << "FragTrap " << this->_name << " constructor called" << RST << std::endl;
}

FragTrap::FragTrap(const FragTrap &src) : ClapTrap(src)
{
	*this = src;
	std::cout << G << "FragTrap " << this->_name << " copy constructor called" << RST << std::endl;
}

FragTrap& FragTrap::operator= (const FragTrap &src)
{
	if (this != &src)
	{
		this->_name = src._name;
		this->_hitPoints = src._hitPoints;
		this->_energyPoints = src._energyPoints;
		this->_attackDamage = src._attackDamage;
	}
	std::cout << G << "FragTrap " << this->_name << " copy assignment operator called" << RST << std::endl;
	return *this;
}

FragTrap::~FragTrap()
{
	std::cout << R << "FragTrap " << this->_name << " destroyed" << RST << std::endl;
}

void	FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap " << this->_name << " is requesting a high five! ?" << std::endl;
}