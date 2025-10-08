#pragma once
#include <iostream>
#include <cmath>

#define RST "\033[0m"      // reset color
#define R "\033[1;31m"   // bold red
#define G   "\033[1;32m"   // bold green

class Fixed
{
private:
	int					_fixedPoint;
	static const int	_bits = 8;
public:
	Fixed();
	Fixed(const int intNum);
	Fixed(const float floatNum);
	Fixed(const Fixed &src);
	Fixed& operator= (const Fixed &src);
	~Fixed();
	
	int getRawBits() const;
	void setRawBits(int const raw);
	float toFloat() const;
	int toInt() const;
};

std::ostream &operator<<(std::ostream &output, const Fixed &f);