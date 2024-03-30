#include "ScalarConverter.hpp"
#include "TypeDetecter.hpp"
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
	try
	{
		std::string	scalarType = TypeDetecter::getScalarType(string);

		if (scalarType == "char")
			ScalarPrinter::printScalar(Converter::convertToChar(string));
		else if (scalarType == "int")
			ScalarPrinter::printScalar(Converter::convertToInt(string));
		else if (scalarType == "float")
			ScalarPrinter::printScalar(Converter::convertToFloat(string));
		else
			ScalarPrinter::printScalar(Converter::convertToDouble(string));
	}
	catch (const std::exception& exception)
	{
		ScalarPrinter::printScalar(exception);
	}
}