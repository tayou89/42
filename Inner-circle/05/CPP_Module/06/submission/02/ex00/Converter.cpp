#include "Converter.hpp"
#include "ScopeChecker.hpp"
#include <cstdlib>

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

char	Converter::convertToChar(const std::string &charLiteral)
{
	return (charLiteral[1]);
}

char	Converter::convertToChar(const int &integer) throw (std::exception)
{
	if (ScopeChecker::isCharScope(integer) == false)
		throw (Converter::UnconvertableException());
	if (ScopeChecker::isDisplayableChar(static_cast<char>(integer)) == false)
		throw (Converter::NonDisplayableException());
	return (static_cast<char>(integer));
}

char	Converter::convertToChar(const float &floatNumber) throw (std::exception)
{
	if (ScopeChecker::isCharScope(floatNumber) == false)
		throw (Converter::UnconvertableException());
	if (ScopeChecker::isDisplayableChar(static_cast<char>(floatNumber)) == false)
		throw (Converter::NonDisplayableException());
	return (static_cast<char>(floatNumber));
}

char	Converter::convertToChar(const double &doubleNumber) throw (std::exception)
{
	if (ScopeChecker::isCharScope(doubleNumber) == false)
		throw (Converter::UnconvertableException());
	if (ScopeChecker::isDisplayableChar(static_cast<char>(doubleNumber)) == false)
		throw (Converter::NonDisplayableException());
	return (static_cast<char>(doubleNumber));
}

int	Converter::convertToInt(const std::string &intLiteral)
{
	return (std::atoi(intLiteral.c_str()));
}

int	Converter::convertToInt(const char &character)
{
	return (static_cast<int>(character));
}

int	Converter::convertToInt(const float &floatNumber) throw (std::exception)
{
	if (ScopeChecker::isIntScope(floatNumber) == false)
		throw (Converter::UnconvertableException());
	return (static_cast<int>(floatNumber));
}

int	Converter::convertToInt(const double &doubleNumber) throw (std::exception)
{
	if (ScopeChecker::isIntScope(doubleNumber) == false)
		throw (Converter::UnconvertableException());
	return (static_cast<int>(doubleNumber));
}

float	Converter::convertToFloat(const std::string &floatLiteral)
{
	char	*endString = NULL;

	return (static_cast<float>(std::strtod(floatLiteral.c_str(), &endString)));
}

float	Converter::convertToFloat(const char &character)
{
	return (static_cast<float>(character));
}

float	Converter::convertToFloat(const int &integer)
{
	return (static_cast<float>(integer));
}

float	Converter::convertToFloat(const double &doubleNumber)
{
	return (static_cast<float>(doubleNumber));
}

double	Converter::convertToDouble(const std::string &doubleLiteral)
{
	char	*endString = NULL;

	return (std::strtod(doubleLiteral.c_str(), &endString));
}

double	Converter::convertToDouble(const char &character)
{
	return (static_cast<double>(character));
}

double	Converter::convertToDouble(const int &integer)
{
	return (static_cast<double>(integer));
}

double	Converter::convertToDouble(const float &floatNumber)
{
	return (static_cast<double>(floatNumber));
}

const char	*Converter::UnconvertableException::what(void) const throw()
{
	return ("impossible");
}

const char	*Converter::NonDisplayableException::what(void) const throw()
{
	return ("Non displayable");
}