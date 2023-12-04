#include <iostream>
#include "Point.hpp"
#include "Fixed.hpp"

bool	bsp(Point const a, Point const b, Point const c, Point const point);
void	printEveryPoint(Point const a, Point const b, Point const c, Point const point);
void	printPoint(std::string prompt, Point point);
void	printBSPResult(bool BSPResult);

int	main(void)
{
	Point	trianglePointA(1.5f, 0);
	Point	trianglePointB(-1.5f, 0);
	Point	trianglePointC(0, 1.5f);
	Point	pointToCheck1(0, 1.49f);
	Point	pointToCheck2(0, 1.6f);
	bool	result;

	printEveryPoint(trianglePointA, trianglePointB, trianglePointC, pointToCheck1);
	result = bsp(trianglePointA, trianglePointB, trianglePointC, pointToCheck1);
	printBSPResult(result);
	std::cout << std::endl;

	printEveryPoint(trianglePointA, trianglePointB, trianglePointC, pointToCheck2);
	result = bsp(trianglePointA, trianglePointB, trianglePointC, pointToCheck2);
	printBSPResult(result);
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

void	printBSPResult(bool BSPResult)
{
	if (BSPResult == true)
		std::cout << "The point is inside of triangle." << std::endl;
	else
		std::cout << "The point is not inside of triangle." << std::endl;
}
