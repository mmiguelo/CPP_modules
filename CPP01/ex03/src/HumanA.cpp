#include "../HumanA.hpp"
#include "../Weapon.hpp"

HumanA::HumanA(Weapon &weapon, std::string name) : _weapon(weapon), _name(name)
{}

HumanA::~HumanA()
{}

void	HumanA::attack()
{
	std::cout << this->_name << " attacks with his " << this->_weapon.getType() << std::endl;
}
