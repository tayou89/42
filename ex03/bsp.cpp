#include <iostream>
#include "Point.hpp"
#include "Fixed.hpp"

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
	Fixed	negative(-1);

}

void	printEveryPoint(Point const a, Point const b, Point const c, Point const point)
{
	printPoint("Triangle point 1: ", a);
	printPoint("Triangle point 2: ", b);
	printPoint("Triangle point 3: ", c);
	printPoint("Point to check: ", point);
}

void	printPoint(std::string prompt, Point point)
{
	Fixed	coordinateX = point.getCoordinateX();
	Fixed	coordinateY = point.getCoordinateY();

	std::cout << prompt;
	std::cout << "( " << coordinateX.toFloat();
	std::cout << ", " << coordinateY.toFloat() << " )";
}
