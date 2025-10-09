#include "../ScavTrap.hpp"
#include "../ClapTrap.hpp"
#include "../FragTrap.hpp"
#include "../DiamondTrap.hpp"

int	main()
{
    std::cout << "\n===== CREATING TRAPS =====\n" << std::endl;
	ClapTrap	clap("CLAP-TP");
	ScavTrap	scav("SCAV-TP");
	FragTrap	frag("FRAG-TP");
	DiamondTrap	diamond("DIAM-TP");

	std::cout << "\n=====  BASIC ATTACK TESTS =====\n" << std::endl;
	clap.attack("a bandit");
	scav.attack("a skag");
	frag.attack("a badass psycho");
	diamond.attack("Handsome Jack");

	std::cout << "\n=====  SPECIAL ABILITIES =====\n" << std::endl;
	scav.guardGate();
	frag.highFivesGuys();
	diamond.whoAmI();

	std::cout << "\n=====  DAMAGE / REPAIR TESTS =====\n" << std::endl;
	diamond.takeDamage(50);
	diamond.beRepaired(30);
	diamond.takeDamage(200);

	std::cout << "\n===== COPY AND ASSIGNMENT TEST =====\n" << std::endl;
	DiamondTrap copyDiamond(diamond); // Copy constructor
	DiamondTrap assignedDiamond;
	assignedDiamond = diamond; // Assignment operator

	std::cout << "\n===== DESTRUCTION ORDER =====\n" << std::endl;
	return 0;   
}
