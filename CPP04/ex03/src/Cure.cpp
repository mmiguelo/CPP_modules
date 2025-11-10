#include "../Cure.hpp"
#include "../ICharacter.hpp"

Cure::Cure() : AMateria("cure")
{
	std::cout << G << "Cure: Default constructor called" << RST << std::endl;
}

Cure::Cure(const Cure &other) : AMateria(other)
{
	std::cout << G << "Cure: Copy constructor called" << RST << std::endl;
}

Cure &Cure::operator=(const Cure &other)
{
	std::cout << G << "Cure: Copy assignment operator called" << RST << std::endl;
	if (this != &other)
		this->type = other.type;
	return *this;
}

Cure::~Cure()
{
	std::cout << R << "Cure: Destructor called" << RST << std::endl;
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