#include "Point.hpp"

Point::Point(void)
	: x(0), y(0)
{
}

Point::~Point(void)
{
}

Point::Point(const Point &object)
{
	*this = object;
}

Point	&Point::operator=(const Point &object)
{
	if (this != &object)
	{
		const_cast<Fixed &>(x) = object.getCoordinateX();
		const_cast<Fixed &>(y) = object.getCoordinateY();
	}
	return (*this);
}

Point::Point(const float number1, const float number2)
	: x(number1), y(number2)
{
}

Fixed	Point::getCoordinateX(void) const
{
	return (x);
}

Fixed	Point::getCoordinateY(void) const
{
	return (y);
}
