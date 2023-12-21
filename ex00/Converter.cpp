#include "Converter.hpp"
#include <cstdlib>
#include <limits>
#include <cmath>

Converter::Converter(void)
{
}

Converter::~Converter(void)
{
}

Converter::Converter(const Converter &object)
{
	*this = object;
}

Converter	&Converter::operator=(const Converter &object)
{
	if (this == &object)
		return (*this);
	return (*this);
}

double	Converter::stringToDouble(const std::string &string) throw (std::exception)
{
	char		*restChar = NULL;
	double		doubleNumber = std::strtod(string.c_str(), &restChar);;
	std::string	restString = restChar;

	if (doubleNumber == 0)
	{
		if (string.size() == 0)
			throw Converter::UnconvertableException();
		if (string.size() == 1 && string != "0")
			throw Converter::UnconvertableException();
	}
	if (restString.size() > 0 && restString != "f")
		throw Converter::UnconvertableException();
	return (doubleNumber);
}

char	Converter::doubleToChar(const double doubleNumber) throw (std::exception)
{
	double	charMIN = std::numeric_limits<char>::min();
	double	charMAX = std::numeric_limits<char>::max();

	if (std::isnan(doubleNumber) || std::isinf(doubleNumber))
		throw Converter::UnconvertableException();
	if (doubleNumber <= charMIN - 1.0 || doubleNumber >= charMAX + 1.0)
		throw Converter::UnconvertableException();
	if (doubleNumber < 32.0 || doubleNumber >= 127.0)
		throw Converter::UndisplayableException();
	return (static_cast<char>(doubleNumber));
}

# include <iostream>

int	Converter::doubleToInt(const double doubleNumber) throw (std::exception)
{
	double	intMIN = std::numeric_limits<int>::min();
	double	intMAX = std::numeric_limits<int>::max();

	if (std::isnan(doubleNumber) || std::isinf(doubleNumber))
		throw Converter::UnconvertableException();
	if (doubleNumber <= intMIN - 1.0 || doubleNumber >= intMAX + 1.0)
		throw Converter::UnconvertableException();
	return (static_cast<int>(doubleNumber));
}

float	Converter::doubleToFloat(const double doubleNumber)
{
	return (static_cast<float>(doubleNumber));
}

const char	*Converter::UnconvertableException::what(void) const throw()
{
	return ("Impossible");
}

const char	*Converter::UndisplayableException::what(void) const throw()
{
	return ("Non displayable");
}