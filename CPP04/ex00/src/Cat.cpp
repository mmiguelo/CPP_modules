#include "../Cat.hpp"
#include "../Animal.hpp"

Cat::Cat() : Animal()
{
    this->type = "Cat";
    std::cout << "Cat default constructor called" << std::endl;
}

Cat::Cat(const Cat &other) : Animal(other)
{
    std::cout << "Cat copy constructor called" << std::endl;
    *this = other;
}

Cat::~Cat()
{
    std::cout << "Cat destructor called" << std::endl;
}

Cat& Cat::operator= (const Cat &other)
{
    std::cout << "Cat copy assignment operator called" << std::endl;
    if (this != &other)
        this->type = other.type;
    return *this;
}

void Cat::makeSound() const
{
    std::cout << "Meow Meow *Licks paw* " << std::endl;
}