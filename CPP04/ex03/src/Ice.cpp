#include "../Ice.hpp"

Ice::Ice() : AMateria("ice")
{
	std::cout << B << "Ice: Default constructor called" << RST << std::endl;
}

Ice::Ice(const Ice &other) : AMateria(other)
{
	std::cout << B << "Ice: Copy constructor called" << RST << std::endl;
}

Ice &Ice::operator=(const Ice &other)
{
	std::cout << B << "Ice: Copy assignment operator called" << RST << std::endl;
	if (this != &other)
		this->type = other.type;
	return *this;
}

Ice::~Ice()
{
	std::cout << B << "Ice: Destructor called" << RST << std::endl;
}

Ice* Ice::clone() const
{
	Ice *temp;

	temp = new Ice(*this);
	return temp;
}

void Ice::use(ICharacter& target)
{
	std::cout << B << "Ice: \'* shoots an ice bolt at " << target.getName() << " *\'" << RST << std::endl;
}