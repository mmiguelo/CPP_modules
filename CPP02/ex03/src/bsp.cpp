#include "../Point.hpp"

static double calculateTriangleArea(const Point &A, const Point &B, const Point &C)
{
    //  Determinant form
    // A = 1/2 * |x1(y2 - y3) + x2(y3 - y1) + x3 (y1 - y2)|
    double x1 = A.getX().toFloat();
    double y1 = A.getY().toFloat();
    double x2 = B.getX().toFloat();
    double y2 = B.getY().toFloat();
    double x3 = C.getX().toFloat();
    double y3 = C.getY().toFloat();

	double area = 1.0/2.0 * fabs(x1*(y2 - y3) + x2*(y3 - y1) + x3*(y1 - y2));

	return area;
}

bool bsp(const Point &A, const Point &B, const Point &C, const Point &p)
{
	double totalArea = calculateTriangleArea(A, B, C);
	double area1 = calculateTriangleArea(A, B, p);
	double area2 = calculateTriangleArea(A, p, C);
	double area3 = calculateTriangleArea(p, B, C);

	{
		std::cout << "Total Area: " << totalArea << std::endl;
		std::cout << "Area of Triangle 1: " << area1 << std::endl;
		std::cout << "Area of Triangle 2: " << area2 << std::endl;
		std::cout << "Area of Triangle 3: " << area3 << std::endl;
		std::cout << "Is Point inside of triangle: " << (totalArea == area1 + area2 + area3 ? "true" : "false") << std::endl;
	}
	
	return (totalArea == area1 + area2 + area3);
}
