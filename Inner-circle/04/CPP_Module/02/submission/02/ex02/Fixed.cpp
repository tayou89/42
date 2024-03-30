#include "Fixed.hpp"
#include <iostream>
#include <cmath>

Fixed::Fixed(void)
	: _fixedPointValue(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed &origin)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = origin;
}

Fixed	&Fixed::operator=(const Fixed &origin)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &origin)
		this->_fixedPointValue = origin.getRawBits();
	return (*this);
}

int		Fixed::getRawBits(void) const
{
	return (_fixedPointValue);
}

void	Fixed::setRawBits(int const number)
{
	_fixedPointValue = number;
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

bool	Fixed::operator>(const Fixed &object) const
{
	return (this->_fixedPointValue > object.getRawBits());
}

bool	Fixed::operator<(const Fixed &object) const
{
	return (this->_fixedPointValue < object.getRawBits());
}

bool	Fixed::operator>=(const Fixed &object) const
{
	return (this->_fixedPointValue >= object.getRawBits());
}

bool	Fixed::operator<=(const Fixed &object) const
{
	return (this->_fixedPointValue <= object.getRawBits());
}

bool	Fixed::operator==(const Fixed &object) const
{
	return (this->_fixedPointValue == object.getRawBits());
}

bool	Fixed::operator!=(const Fixed &object) const
{
	return (this->_fixedPointValue != object.getRawBits());
}

Fixed	Fixed::operator+(const Fixed &object) const
{
	Fixed	result(this->toFloat() + object.toFloat());

	return (result);
}

Fixed	Fixed::operator-(const Fixed &object) const
{
	Fixed	result(this->toFloat() - object.toFloat());

	return (result);
}

Fixed	Fixed::operator*(const Fixed &object) const
{
	Fixed	result(this->toFloat() * object.toFloat());

	return (result);
}

Fixed	Fixed::operator/(const Fixed &object) const
{
	Fixed	result(this->toFloat() / object.toFloat());

	return (result);
}

Fixed	&Fixed::operator++(void)
{
	++_fixedPointValue;
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed	copy = *this;

	++_fixedPointValue;
	return (copy);
}

Fixed	&Fixed::operator--(void)
{
	--_fixedPointValue;
	return (*this);
}

Fixed	Fixed::operator--(int)
{
	Fixed	copy = *this;

	--_fixedPointValue;
	return (copy);
}

Fixed	&Fixed::min(Fixed &number1, Fixed &number2) 
{
	return (number1 < number2 ? number1 : number2);
}

const Fixed	&Fixed::min(const Fixed &number1, const Fixed &number2) 
{
	return (number1 < number2 ? number1 : number2);
}

Fixed	&Fixed::max(Fixed &number1, Fixed &number2) 
{
	return (number1 > number2 ? number1 : number2);
}

const Fixed	&Fixed::max(const Fixed &number1, const Fixed &number2) 
{
	return (number1 > number2 ? number1 : number2);
}
