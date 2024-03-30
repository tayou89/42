#include <iostream>
#include "Point.hpp"
#include "Fixed.hpp"

void	printEveryPoint(Point const a, Point const b, Point const c, Point const point);
void	printPoint(std::string prompt, Point point);
bool	bsp(Point const a, Point const b, Point const c, Point const point);

int	main(void)
{
	Point	trianglePointA(5, 5);
	Point	trianglePointB(2, 9);
	Point	trianglePointC(0, 5);
	Point	pointToCheck1(3, 7);
	Point	pointToCheck2(4, 7);

	printEveryPoint(trianglePointA, trianglePointB, trianglePointC, pointToCheck1);
	if (bsp(trianglePointA, trianglePointB, trianglePointC, pointToCheck1) == true)
		std::cout << "The point is inside of triangle." << std::endl;
	else
		std::cout << "The point is not inside of triangle." << std::endl;
	std::cout << std::endl;

	printEveryPoint(trianglePointA, trianglePointB, trianglePointC, pointToCheck2);
	if (bsp(trianglePointA, trianglePointB, trianglePointC, pointToCheck2) == true)
		std::cout << "The point is inside of triangle." << std::endl;
	else
		std::cout << "The point is not inside of triangle." << std::endl;
	return (0);
}

void	printEveryPoint(Point const a, Point const b, Point const c, Point const point)
{
	printPoint("Triangle point a: ", a);
	printPoint("Triangle point b: ", b);
	printPoint("Triangle point c: ", c);
	printPoint("Point to check: ", point);
}

void	printPoint(std::string prompt, Point point)
{
	Fixed	coordinateX = point.getCoordinateX();
	Fixed	coordinateY = point.getCoordinateY();

	std::cout << prompt;
	std::cout << "( " << coordinateX.toFloat();
	std::cout << ", " << coordinateY.toFloat() << " )" << std::endl;
}
