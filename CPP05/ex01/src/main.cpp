#include "../Bureaucrat.hpp"
#include "../Form.hpp"

int main()
{
	std::cout << B << "\n	Bureaucrat Creation\n" << RST;
	Bureaucrat ham("Hamilton", 4);
	Bureaucrat ver("Verstappen", 2);

	std::cout << B << "\n	Form Creation\n" << RST;
	Form ferrari("Ferrari", 4, 4);
	Form redbull("RedBull", 1, 1);

	std::cout << B << "\n	Form Details\n" << RST;
	std::cout << ferrari << std::endl;
	std::cout << redbull << std::endl;

	std::cout << B << "	Sign Forms\n" << RST;
	ham.signForm(ferrari);
	ham.signForm(ferrari);
	ham.signForm(redbull);
	ver.signForm(redbull);

	std::cout << B << "\n	Form Details Again\n" << RST;
	std::cout << ferrari << std::endl;
	std::cout << redbull << std::endl;

	std::cout << B << "	Verstappen increment and sign form\n" << RST;
	ver.incrementGrade();
	ver.signForm(redbull);
	std::cout << redbull << std::endl;

	std::cout << B << "	Out of Range Form Creation\n" << RST;
	try {
		Form haas("Haas", 200, 200);
	} catch (std::exception& error) {
		std::cout << error.what() << std::endl;
	}
	try {
		Form williams("Williams", -1, -1);
	} catch (std::exception& error) {
		std::cout << error.what() << std::endl;
	}

	std::cout << B << "\n	Destruction\n" << RST;
	return (0);
}