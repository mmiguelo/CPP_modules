#include "../Cure.hpp"

Cure::Cure() : AMateria("Cure")
{
	std::cout << B << "Cure: Default constructor called" << RST << std::endl;
}

Cure::Cure(const Cure &other) : AMateria(other)
{
	std::cout << B << "Cure: Copy constructor called" << RST << std::endl;
}

Cure &Cure::operator=(const Cure &other)
{
	std::cout << B << "Cure: Copy assignment operator called" << RST << std::endl;
	if (this != &other)
		this->type = other.type;
	return *this;
}

Cure::~Cure()
{
	std::cout << B << "Cure: Destructor called" << RST << std::endl;
}

Cure* Cure::clone() const
{
	Cure *temp;

	temp = new Cure(*this);
	return temp;
}

void Cure::use(ICharacter& target)
{
	std::cout << B << "Cure: \'* heals " << target.getName() << "'s wounds *\'" << RST << std::endl;
}