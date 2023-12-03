#include <iostream>
#include "Point.hpp"
#include "Fixed.hpp"

int	main(void)
{
	Point	trianglePoint1(1.5f, 0);
	Point	trianglePoint2(-1.5f, 0);
	Point	trianglePoint3(0, 1.5f);
	point	pointToCheck(3, 3);

	if (bsp(trianglePoint1, trianglePoint2, trianglePoint3, pointToCheck) == true)
		std::cout << "The point is inside of triangle." << std::endl;
	else
		std::cout << "The point is not inside of triangle." << std:endl;
	return (0);
}
