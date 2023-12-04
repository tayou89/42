#include <iostream>
#include "Point.hpp"
#include "Fixed.hpp"

Fixed	getCrossProduct(Point vector1, Point vector2);
bool	isPointOnTriangleEdge(Fixed crossProduct[3]);
bool	isPointOnTriangleInside(Fixed crossProduct[3]);

bool	bsp(Point const a, Point const b, Point const c, Point const point)
{
	Fixed	crossProduct[3] = { getCrossProduct(b - a, point - a),
								getCrossProduct(c - b, point - b),
								getCrossProduct(a - c, point - c) };

	if (isPointOnTriangleInside(crossProduct) == true)
		return (true);
	else
	{
		if (isPointOnTriangleEdge(crossProduct) == true)
			std::cout << "The point is on the edge of triangle." << std::endl;
		return (false);
	}
}

Fixed	getCrossProduct(Point vector1, Point vector2)
{
	Fixed	crossProductZvalue;

	crossProductZvalue = vector1.getCoordinateX() * vector2.getCoordinateY()
					   - vector1.getCoordinateY() * vector2.getCoordinateX();
	return (crossProductZvalue);
}

bool	isPointOnTriangleEdge(Fixed crossProduct[3])
{
	int	i;

	for (i = 0; i < 3; i++)
	{
		if (crossProduct[i] == Fixed(0))
			return (true);
	}
	return (false);
}

bool	isPointOnTriangleInside(Fixed crossProduct[3])
{
	if (crossProduct[0] > Fixed(0) &&
		crossProduct[1] > Fixed(0) &&
		crossProduct[2] > Fixed(0))
		return (true);
	else if (crossProduct[0] < Fixed(0) &&
			 crossProduct[1] < Fixed(0) &&
			 crossProduct[2] < Fixed(0))
		return (true);
	else
		return (false);
}
