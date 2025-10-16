#include "../AAnimal.hpp"

AAnimal::AAnimal() : type("")
{
    std::cout << "Animal default constructor called" << std::endl;
}

AAnimal::AAnimal(const AAnimal &other)
{
    std::cout << "Animal copy constructor called" << std::endl;
    *this = other;
}

AAnimal::~AAnimal()
{
    std::cout << "Animal destructor called" << std::endl;
}

AAnimal& AAnimal::operator= (const AAnimal &other)
{
    std::cout << "Animal copy assignment operator called" << std::endl;
	if (this != &other)
		this->type = other.type;
	return *this;
}

std::string AAnimal::getType() const
{
    return this->type;
}
