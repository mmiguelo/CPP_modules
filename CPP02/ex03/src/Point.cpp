#include "../Point.hpp"

Point::Point(void) : _x(0), _y(0)
{}

Point::Point(int x, int y) : _x(x), _y(y)
{}

Point::Point(float x, float y) : _x(x), _y(y)
{}

Point::Point(const Point &src)
{
    *this=src;
}

Point::~Point(void)
{}

Point& Point::operator= (const Point &src)
{
	if (this != &src)
		std::cout << "Shouldnt let point coord to be const" << std::endl;
	return *this;
}

Fixed Point::getX(void) const
{
    return this->_x;
}

Fixed Point::getY(void) const
{
    return this->_y;
}