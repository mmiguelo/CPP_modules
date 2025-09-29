#include "../sed.hpp"

int main(int ac, char **av)
{
	if (ac != 4)
	{
		std::cout << "usage: [executable] [filename] [s1] [s2]" << std::endl;
		return (1);
	}

	sed(av[1], av[2], av[3]);
	return (0);
}