#include "../Fixed.hpp"

int main()
{
	Fixed a; //creates a new instance of class Fixed called a with value 0
	Fixed b(a); //creates a new instance of class Fixed called b as a copy of class Fixed a which the copy constructor assigns the values of a to b
	Fixed c; //creates a new instance of class Fixed called c with value 0

	c = a; //assigns the values of a to c using the copy assignment operator - in this case is redundant
	
	std::cout << a.getRawBits() << std::endl;
	std::cout << b.getRawBits() << std::endl;
	std::cout << c.getRawBits() << std::endl;
	return 0;
}
