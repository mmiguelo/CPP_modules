#include "../span.hpp"

span::span() : _N(0)
{
	std::cout << G << "span: default constructor called" << RST << std::endl;
}

Span::Span(unsigned int nbr) : _N(nbr)
{
    std::cout << G << "Span was created with " << nbr << " elements" << RST << std::endl;
}

span::~span()
{
	std::cout << R << "span: destructor called" << RST << std::endl;
}

span::span(const span &other) : _N(other._N)
{
    std::cout << G << "span: Copy constructor called." << RST << std::endl;
    for (size_t i = 0; i < other.storage.size(); i++)
        this->storage[i] = other.storage[i];
}

span& span::operator=(const span &other) {
    if (this != &other) {
        this->_N = other._N;
        for (size_t i = 0; i < other.storage.size(); i++)
            this->storage[i] = other.storage[i];
    }
    std::cout << G << "Copy assignment operator called" << RST << std::endl;
    return *this;
}

void Span::addNumber()
{
    
}