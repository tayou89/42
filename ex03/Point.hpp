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

		Fixed	getCoordinateX(void) const;
		Fixed	getCoordinateY(void) const;

	private:
		void	setCoordinateX(const Fixed x);
		void	setCoordinateY(const Fixed y);

		Fixed	x;
		Fixed	y;
};

#endif
