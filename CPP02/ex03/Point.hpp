#pragma once

#include "Fixed.hpp"

class Point
{
    private:
        Fixed const _x;
        Fixed const _y;
    public:
        Point(void);
		Point(int x, int y);
		Point(float x, float y);
		Point(const Point &src);
		~Point(void);

		Fixed getX(void) const;
		Fixed getY(void) const;

		Point& operator= (const Point &src);
};