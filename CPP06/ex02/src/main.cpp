#include "../Base.hpp"
#include "../A.hpp"
#include "../B.hpp"
#include "../C.hpp"

int main()
{
	std::srand(std::time(0));

	std::cout << std::endl << BL "Generating objects" RST << std::endl;
	Base* random1 = generate();
	Base* random2 = generate();
	Base* random3 = generate();
	Base* random4 = generate();

	std::cout << std::endl << BL "Identity check using pointers: " RST << std::endl;
	identify(random1);
	identify(random2);
	identify(random3);
	identify(random4);

	std::cout << std::endl << BL "Identity check using references: " RST << std::endl;
	identify(*random1);
	identify(*random2);
	identify(*random3);
	identify(*random4);

	std::cout << std::endl << BL "Cleaning" RST << std::endl;
	delete (random1);
	delete (random2);
	delete (random3);
	delete (random4);
	return (0);
}