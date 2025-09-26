#include "../Zombie.hpp"

int main()
{
	int N;
	std::string name;

	while (!std::cin.eof())
	{
		std::cout << "Enter amount of Zombies between 1 and 1000: ";
		std::cin >> N;
		if (std::cin.fail() || N <= 0 || N > 1000)
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cerr << "Error: Invalid input. Please enter a positive integer between 1 and 1000." << std::endl;
		}
		else
			break ;
	}
	std::cout << "Enter Zombie name: ";
	std::cin >> name;
	Zombie *horde = zombieHorde(N, name);
	if (!horde)
	{
		std::cerr << "Error: Memory allocation failed" << std::endl;
		return (1);
	}
	for (int i = 0; i < N; i++)
		horde[i].announce();		
	delete [] horde; //have to manually delete the array created with new
	return (0);
}
