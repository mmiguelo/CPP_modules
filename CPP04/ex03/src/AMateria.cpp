#include "../AMateria.hpp"

AMateria::AMateria() : type("default")
{
	std::cout << G << "AMateria: Default constructor called" << RST << std::endl;
}

AMateria::AMateria(const AMateria &other)
{
	std::cout << G << "AMateria: Copy constructor called" << RST << std::endl;
	if (this != &other)
		this->type = other.type;
}

AMateria::AMateria(std::string const &type) : type(type)
{
	std::cout << G << "AMateria: Parameterized constructor called" << RST << std::endl;
}

AMateria &AMateria::operator=(const AMateria &other)
{
	std::cout << Y << "AMateria: Copy assignment operator called" << RST << std::endl;
	if (this != &other)
		this->type = other.type;
	return *this;
}

AMateria::~AMateria()
{
	std::cout << R << "AMateria: Destructor called" << RST << std::endl;
}

void AMateria::use(ICharacter& target)
{
	std::cout << "AMateria: \"* does nothing to " << target.getName() << "*\"" << std::endl;
}

std::string const & AMateria::getType() const
{
	return this->type;
}