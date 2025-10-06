#include "../Fixed.hpp"

int main()
{
	Fixed *a = new Fixed();
	Fixed b(*a);
	Fixed c;

	c = *a;

	std::cout << a->getRawBits() << std::endl;
	delete a;
	std::cout << b.getRawBits() << std::endl;
	std::cout << c.getRawBits() << std::endl;

	return 0;
}
