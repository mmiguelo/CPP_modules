#include "../ScavTrap.hpp"
#include "../ClapTrap.hpp"

int	main()
{
	{
        std::cout << std::endl << "-------------TESTE1------------------" << std::endl;
        ClapTrap clapTrap("shrek");
        ScavTrap ScavTrap("Kratos");

        clapTrap.attack("kratos");
        ScavTrap.takeDamage(0);
        ScavTrap.beRepaired(0);
        ScavTrap.attack("shrek");
        clapTrap.takeDamage(20);
        clapTrap.beRepaired(20);
        ScavTrap.guardGate();

    }
    {
        std::cout  << std::endl << "-------------TESTE2------------------" << std::endl;
        ClapTrap clapTrap;
        ClapTrap clapTrap2("Palagoso");
        ScavTrap ScavTrap2("IDK2");
        ScavTrap ScavTrap("IDK");

        clapTrap2.attack("ClapTrap");
        clapTrap.takeDamage(5);
        clapTrap.beRepaired(5);
        ScavTrap.attack("IDK2");
        ScavTrap2.takeDamage(80);
        ScavTrap2.beRepaired(80);
        ScavTrap2.guardGate();
    }
    {
        std::cout << std::endl << "-------------TESTE3------------------" << std::endl;
        ClapTrap clapTrap3("El Primo");

        clapTrap3.takeDamage(5);
        clapTrap3.beRepaired(5);
        clapTrap3.attack("Sipder Man");
        clapTrap3.takeDamage(5);
        clapTrap3.beRepaired(5);
        clapTrap3.attack("Sipder Man");
        clapTrap3.takeDamage(5);
        clapTrap3.beRepaired(5);
        clapTrap3.attack("Sipder Man");
        clapTrap3.takeDamage(5);
        clapTrap3.beRepaired(5);
        clapTrap3.attack("Sipder Man");
        clapTrap3.takeDamage(5);
        clapTrap3.beRepaired(5);
        clapTrap3.attack("Sipder Man");
        clapTrap3.takeDamage(5);
        clapTrap3.beRepaired(5);
        clapTrap3.attack("Sipder Man");
    }
    return 0;
}
