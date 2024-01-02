#include "Converter.hpp"
#include <cstdlib>
#include <limits>
#include <cmath>

Converter::Converter(void)
	: character(0), integer(0), floatNumber(0.0f), doubleNumber(0)
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

char	Converter::convertToChar(const std::string &charLiteral)
{
	char	character = charLiteral[1];

	if (
	return (charLiteral[1]);
}

int	Converter::convertToInt(const std::string &intLiteral)
{

}