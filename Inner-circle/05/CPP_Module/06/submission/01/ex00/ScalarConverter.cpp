#include "ScalarConverter.hpp"
#include "Converter.hpp"
#include "ScalarPrinter.hpp"

ScalarConverter::ScalarConverter(void)
{
}

ScalarConverter::~ScalarConverter(void)
{
}

ScalarConverter::ScalarConverter(const ScalarConverter &object)
{
	*this = object;
}

ScalarConverter	&ScalarConverter::operator=(const ScalarConverter &object)
{
	if (this == &object)
		return (*this);
	return (*this);
}

void	ScalarConverter::convert(const std::string &string)
{
	double	doubleNumber;
	char	character;
	int		integer;
	float	floatNumber;

	try
	{
		doubleNumber = Converter::stringToDouble(string);
	}
	catch (const std::exception	&exception)
	{
		ScalarPrinter::printChar(exception);
		ScalarPrinter::printInt(exception);
		ScalarPrinter::printFloat(exception);
		ScalarPrinter::printDouble(exception);
		return ;
	}

	try
	{
		character = Converter::doubleToChar(doubleNumber);
		ScalarPrinter::printChar(character);
	}
	catch (const std::exception &exception)
	{
		ScalarPrinter::printChar(exception);
	}

	try
	{
		integer = Converter::doubleToInt(doubleNumber);
	 	ScalarPrinter::printInt(integer);
	}
	catch (const std::exception &exception)
	{
	 	ScalarPrinter::printInt(exception);
	}

	floatNumber = Converter::doubleToFloat(doubleNumber);
	ScalarPrinter::printFloat(floatNumber);
	ScalarPrinter::printDouble(doubleNumber);
}