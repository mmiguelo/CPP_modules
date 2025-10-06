#include "../Fixed.hpp"

Fixed::Fixed() : _value(0)
{
	std::cout << G << "Default constructor called" << RST << std::endl;
}

Fixed::~Fixed()
{
std::cout << R << "Destructor called" << RST << std::endl;
}

Fixed::Fixed(const Fixed &src)
{
	std::cout << G << "Copy constructor called" << RST << std::endl;
	*this = src;
}

Fixed& Fixed::operator=(const Fixed &src)
{
	std::cout << G << "Copy assignment operator called" << RST << std::endl;
	if (this != &src)
		this->_value = src.getRawBits();
	return *this;
}

int Fixed::getRawBits() const
{
	std::cout << G << "getRawBits member function called" << RST << std::endl;
	return this->_value;
}

void Fixed::setRawBits(int const raw)
{
	std::cout << G << "setRawBits member function called" << RST << std::endl;
	this->_value = raw;
}
