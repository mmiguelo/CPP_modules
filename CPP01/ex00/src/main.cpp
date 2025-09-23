#include "../Zombie.hpp"

int main()
{
	Zombie *zombie;
	std::string zombieName;

	std::cout << "Enter Zombie name: ";
	std::cin >> zombieName;
	zombie =  newZombie(zombieName);
	if (!zombie)
	{
		std::cerr << "Error: Memory allocation failed" << std::endl;
		return (1);
	}
	zombie->announce();
	delete zombie; //have to manually delete the zombie created with new
	randomChump("RandomZombie");
	return (0);
}