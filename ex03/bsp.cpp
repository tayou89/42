#include <iostream>
#include "Point.hpp"
#include "Fixed.hpp"

Fixed	getTriangleArea(Point a, Point b, Point c);

bool	bsp(Point const a, Point const b, Point const c, Point const point)
{
	Fixed	triangleArea = getTriangleArea(a, b, c);
	Fixed	insideArea1 = getTriangleArea(a, b, point);
	Fixed	insideArea2 = getTriangleArea(b, c, point);
	Fixed	insideArea3 = getTriangleArea(a, c, point);
	Fixed	insideAreaSum = insideArea1 + insideArea2 + insideArea3;

	if (insideArea1 == 0 || insideArea2 == 0 || insideArea3 == 0)
	{
		std::cout << "The Point is on the edge of the triangle." << std::endl;
		return (false);
	}
	if (insideAreaSum == triangleArea)
		return (true);
	else
		return (false);
}

Fixed	getTriangleArea(Point a, Point b, Point c)
{
	Fixed	triangleArea;
	Fixed	termA;
	Fixed	termB;

	termA = a.getCoordinateX() * b.getCoordinateY() +
			b.getCoordinateX() * c.getCoordinateY() +
			c.getCoordinateX() * a.getCoordinateY();
	termB = a.getCoordinateX() * c.getCoordinateY() +
			c.getCoordinateX() * b.getCoordinateY() +
			b.getCoordinateX() * a.getCoordinateY();
	triangleArea = Fixed(0.5f) * (termA - termB);
	if (triangleArea < Fixed(0))
		triangleArea = triangleArea * Fixed(-1);
	return (triangleArea);
}
