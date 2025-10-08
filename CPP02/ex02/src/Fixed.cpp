#include "../Fixed.hpp"

Fixed::Fixed() : _fixedPoint(0)
{
	std::cout << G << "Default constructor called" << RST << std::endl;
}

Fixed::Fixed(const int intNum)
{
	std::cout << G << "Default Int constructor called" << RST << std::endl;
	this->_fixedPoint = intNum << this->_bits;
}

Fixed::Fixed(const float floatNum)
{
	std::cout << G << "Default Int constructor called" << RST << std::endl;
	this->_fixedPoint = roundf(floatNum * (1 << this->_bits));
}

Fixed::Fixed(const Fixed &src)
{
	std::cout << G << "Copy constructor called" << RST << std::endl;
	*this = src;
}

Fixed& Fixed::operator= (const Fixed &src)
{
	std::cout << G << "Copy assignment operator called" << RST << std::endl;
	if (this != &src)
		this->_fixedPoint = src.getRawBits();
	return *this;
}

Fixed::~Fixed()
{
	std::cout << R << "Destructor called" << RST << std::endl;
}

int Fixed::getRawBits() const
{
	std::cout << G << "getRawBits member function called" << RST << std::endl;
	return this->_fixedPoint;
}

void Fixed::setRawBits(int const raw)
{
	std::cout << G << "setRawBits member function called" << RST << std::endl;
	this->_fixedPoint = raw;
}

float Fixed::toFloat() const
{
	return ((float)this->_fixedPoint / (1 << this->_bits));
}

int Fixed::toInt() const
{
	return (this->_fixedPoint >> this->_bits);
}

std::ostream &operator<<(std::ostream &output, const Fixed &f)
{
	output << f.toFloat();
	return output;
}

bool Fixed::operator>(const Fixed &src) const
{
	return this->_fixedPoint > src.getRawBits();
}

bool Fixed::operator<(const Fixed &src) const
{
	return this->_fixedPoint < src.getRawBits();
}

bool Fixed::operator>=(const Fixed &src) const
{
	return this->_fixedPoint >= src.getRawBits();
}

bool Fixed::operator<=(const Fixed &src) const
{
	return this->_fixedPoint <= src.getRawBits();
}

bool Fixed::operator==(const Fixed &src) const
{
	return this->_fixedPoint == src.getRawBits();
}

bool Fixed::operator!=(const Fixed &src) const
{
	return this->_fixedPoint != src.getRawBits();
}

Fixed Fixed::operator+(const Fixed &src) const
{
	Fixed result;
	result.setRawBits(this->_fixedPoint + src.getRawBits());
	return result;
}

Fixed Fixed::operator-(const Fixed &src) const
{
	Fixed result;
	result.setRawBits(this->_fixedPoint - src.getRawBits());
	return result;
}

Fixed Fixed::operator*(const Fixed &src) const
{
	Fixed result;
	long temp = (long)this->_fixedPoint * (long)src.getRawBits();
	result.setRawBits((int)(temp >> this->_bits));
	return result;
}

Fixed Fixed::operator/(const Fixed &src) const
{
	Fixed result;
	if (src.getRawBits() == 0)
	{
		std::cerr << R << "Error: Division by zero" << RST << std::endl;
		return result;
	}
	long temp = ((long)this->_fixedPoint << this->_bits) / (long)src.getRawBits();
	result.setRawBits((int)temp);
	return result;
}

Fixed& Fixed::operator++() // Prefix increment
{
	this->_fixedPoint++;
	return *this;
}

Fixed Fixed::operator++(int) // Postfix increment
{
	Fixed temp = *this;
	this->_fixedPoint++;
	return temp;
}

Fixed& Fixed::operator--() // Prefix decrement
{
	this->_fixedPoint--;
	return *this;
}

Fixed Fixed::operator--(int) // Postfix decrement
{
	Fixed temp = *this;
	this->_fixedPoint--;
	return temp;
}

Fixed& Fixed::min(Fixed &a, Fixed &b)
{
	return (a < b) ? a : b;
}

const Fixed& Fixed::min(const Fixed &a, const Fixed &b)
{
	return (a < b) ? a : b;
}

Fixed& Fixed::max(Fixed &a, Fixed &b)
{
	return (a > b) ? a : b;
}

const Fixed& Fixed::max(const Fixed &a, const Fixed &b)
{
	return (a > b) ? a : b;
}