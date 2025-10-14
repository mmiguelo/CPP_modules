#pragma once

#include <iostream>
#include <cmath>

#define RST "\033[0m"      // reset color
#define Y ""
#define R "\033[1;31m"   // bold red
#define G   "\033[1;32m"   // bold green

class Fixed
{
	private:
		int					_fixedPoint;
		static const int	_bits = 8;
	public:
		//orthodox canonical form:
		Fixed();
		Fixed(const int intNum);
		Fixed(const float floatNum);
		Fixed(const Fixed &src);
		Fixed& operator= (const Fixed &src);
		~Fixed();

		//methods:
		float toFloat() const;
		int toInt() const;
		int getRawBits() const;
		void setRawBits(int const raw);

		// Comparison operators
		bool operator>(const Fixed &src) const;
		bool operator<(const Fixed &src) const;
		bool operator>=(const Fixed &src) const;
		bool operator<=(const Fixed &src) const;
		bool operator==(const Fixed &src) const;
		bool operator!=(const Fixed &src) const;

		// Arithmetic operators
		Fixed operator+(const Fixed &src) const;
		Fixed operator-(const Fixed &src) const;
		Fixed operator*(const Fixed &src) const;
		Fixed operator/(const Fixed &src) const;

		// Increment and Decrement operators
		Fixed& operator++();       // Prefix increment operator
		Fixed operator++(int);     // Postfix increment operator
		Fixed& operator--();       // Prefix decrement operator
		Fixed operator--(int);     // Postfix decrement operator

		// Static member functions
		static Fixed& min(Fixed &a, Fixed &b);
		static const Fixed& min(const Fixed &a, const Fixed &b);
		static Fixed& max(Fixed &a, Fixed &b);
		static const Fixed& max(const Fixed &a, const Fixed &b);
};

std::ostream &operator<<(std::ostream &output, const Fixed &f);
