#include "../Harl.hpp"

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cerr << R << "Error: bad arguments" << "\n" << "Usage: [Executable] [Level]" << RST << std::endl;
		return 1;
	}
	Harl maleKaren;
	std::string level = av[1];
	maleKaren.filter(level);
	return 0;
}