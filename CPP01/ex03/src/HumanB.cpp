#include "../HumanB.hpp"
#include "../Weapon.hpp"

HumanB::HumanB(std::string name)
{
	this->_name = name;
	this->_weapon = NULL;
};

HumanB::~HumanB()
{}

void	HumanB::attack()
{
	if (this->_weapon)
		std::cout << this->_name << " attacks with his " << (*this->_weapon).getType() << std::endl;
	else
		std::cout << this->_name << " attacks with his bloody fists " << std::endl;
}

void	HumanB::setWeapon(Weapon &weapon)
{
	this->_weapon = &weapon;
}