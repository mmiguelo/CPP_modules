#include "../Ice.hpp"
#include "../ICharacter.hpp"

Ice::Ice() : AMateria("ice")
{
	std::cout << G << "Ice: Default constructor called" << RST << std::endl;
}

Ice::Ice(const Ice &other) : AMateria(other)
{
	std::cout << G << "Ice: Copy constructor called" << RST << std::endl;
}

Ice &Ice::operator=(const Ice &other)
{
	std::cout << G << "Ice: Copy assignment operator called" << RST << std::endl;
	if (this != &other)
		this->type = other.type;
	return *this;
}

Ice::~Ice()
{
	std::cout << R << "Ice: Destructor called" << RST << std::endl;
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