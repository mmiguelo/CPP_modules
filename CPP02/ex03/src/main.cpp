#include "../Point.hpp"

bool bsp(const Point &A, const Point &B, const Point &C, const Point &p);

int main(void)
{
    Point A(0, 0);
    Point B(5, 0);
    Point C(0, 5);

    Point p(5, 0);

    bsp(A, B, C, p);
    return (0);
}