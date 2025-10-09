#include "../ClapTrap.hpp"

int main()
{
	ClapTrap Tobias("Tobias");
	ClapTrap Puff("Puff");

	Tobias.attack("Puff");
	Puff.takeDamage(0);
	Puff.beRepaired(5);
	Puff.attack("Tobias");
	Tobias.takeDamage(3);
	Tobias.beRepaired(2);
	Tobias.attack("Puff");
	Puff.takeDamage(15);
	Puff.takeDamage(5);
	Puff.attack("Tobias");
	Puff.beRepaired(10);
	return 0;
}
