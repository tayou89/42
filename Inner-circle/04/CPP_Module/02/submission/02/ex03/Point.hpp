#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"

class	Point
{
	public:
		Point(void);
		~Point(void);
		Point(const Point &object);
		Point	&operator=(const Point &object);

		Point(const float number1, const float number2);
		Point(const Fixed number1, const Fixed number2);
		Point	operator-(const Point &object) const;
		Fixed	getCoordinateX(void) const;
		Fixed	getCoordinateY(void) const;

	private:
		const Fixed	x;
		const Fixed	y;
};

#endif
