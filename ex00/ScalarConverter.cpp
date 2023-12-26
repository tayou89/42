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

void	ScalarConverter::convert(const std::string string)
{
	std::string	scalarType =   
}