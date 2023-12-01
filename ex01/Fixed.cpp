#include "Fixed.hpp"
#include <iostream>
#include <cmath>

Fixed::Fixed(void)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int number)
{
	std::cout << "Int constructor called" << std::endl;
	_fixedPointValue = number << _fractionalBits;
}

Fixed::Fixed(const float number)
{
	std::cout << "Float constructor called" << std::endl;
	_fixedPointValue = roundf(number * (1 << _fractionalBits));
}

Fixed::Fixed(const Fixed &origin)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = origin;
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

Fixed	&Fixed::operator=(const Fixed &origin)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->_fixedPointValue = origin.getFixedPointValue();
	return (*this);
}

int		Fixed::getFixedPointValue(void) const
{
	return (_fixedPointValue);
}

void	Fixed::_setFixedPointValue(int number)
{
	_fixedPointValue = number;
}

float	Fixed::toFloat(void) const
{
	return ((float) _fixedPointValue / (1 << _fractionalBits));
}

int	Fixed::toInt(void) const
{
	return (_fixedPointValue >> _fractionalBits);
}

std::ostream	&operator<<(std::ostream &stream, const Fixed &object)
{
	stream << object.toFloat();
	return (stream);
}
