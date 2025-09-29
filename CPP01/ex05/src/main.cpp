#include "../Harl.hpp"

int	main()
{
	Harl	maleKaren;

	std::cout << G << "\n[DEBUG]" << RST << std::endl;
	maleKaren.complain("DEBUG");

	std::cout << G << "\n[INFO]" << RST << std::endl;
	maleKaren.complain("INFO");

	std::cout << G << "\n[WARNING]" << RST << std::endl;
	maleKaren.complain("WARNING");

	std::cout << G << "\n[ERROR]" << RST << std::endl;
	maleKaren.complain("ERROR");

	std::cout << G << "\n[UNKNOWN]" << RST << std::endl;
	maleKaren.complain("UNKNOWN");

	return 0;
}