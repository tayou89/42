#include "ScalarPrinter.hpp"
#include "Converter.hpp"
#include "ScopeChecker.hpp"
#include <iostream>
#include <cmath>

ScalarPrinter::ScalarPrinter(void)
{
}

ScalarPrinter::~ScalarPrinter(void)
{
}

ScalarPrinter::ScalarPrinter(const ScalarPrinter &object)
{
	*this = object;
}

ScalarPrinter	&ScalarPrinter::operator=(const ScalarPrinter &object)
{
	if (this == &object)
		return (*this);
	return (*this);
}

void	ScalarPrinter::printScalar(const char &character)
{
	printChar(character);
	printInt(Converter::convertToInt(character));
	printFloat(Converter::convertToFloat(character));
	printDouble(Converter::convertToDouble(character));
}

void	ScalarPrinter::printScalar(const int &integer)
{
	try
	{
		char	character = Converter::convertToChar(integer);
		printChar(character);
	}
	catch(const std::exception& exception)
	{
		printChar(exception);
	}
	printInt(integer);
	printFloat(Converter::convertToFloat(integer));
	printDouble(Converter::convertToDouble(integer));
}

void	ScalarPrinter::printScalar(const float &floatNumber)
{
	try
	{
		char	character = Converter::convertToChar(floatNumber);
		printChar(character);
	}
	catch(const std::exception& exception)
	{
		printChar(exception);
	}

	try
	{
		int	integer = Converter::convertToInt(floatNumber);
		printInt(integer);
	}
	catch(const std::exception& exception)
	{
		printInt(exception);
	}
	printFloat(floatNumber);
	printDouble(Converter::convertToDouble(floatNumber));
}

void	ScalarPrinter::printScalar(const double &doubleNumber)
{
	try
	{
		char	character = Converter::convertToChar(doubleNumber);
		printChar(character);
	}
	catch(const std::exception& exception)
	{
		printChar(exception);
	}

	try
	{
		int	integer = Converter::convertToInt(doubleNumber);
		printInt(integer);
	}
	catch(const std::exception& exception)
	{
		printInt(exception);
	}
	printFloat(Converter::convertToFloat(doubleNumber));
	printDouble(doubleNumber);
}

void	ScalarPrinter::printScalar(const std::exception &exception)
{
	printChar(exception);
	printInt(exception);
	printFloat(exception);
	printDouble(exception);
}

void	ScalarPrinter::printChar(const char &character)
{
	std::cout << "char: \'" << character << "\'\n";
}

void	ScalarPrinter::printChar(const std::exception &exception)
{
	std::cout << "char: " << exception.what() << '\n';
}

void	ScalarPrinter::printInt(const int &integer)
{
	std::cout << "int: " << integer << '\n';
}

void	ScalarPrinter::printInt(const std::exception &exception)
{
	std::cout << "int: " << exception.what() << '\n';
}

void	ScalarPrinter::printFloat(const float &floatNumber)
{
	if (std::isinf(floatNumber) == true)
		std::cout << std::showpos << "float: " << floatNumber << "f\n";
	else
	{
		std::cout.precision(ScopeChecker::getPrecision(floatNumber));
		std::cout << std::fixed << "float: " << floatNumber << "f\n";
	}
}

void	ScalarPrinter::printFloat(const std::exception &exception)
{
	std::cout << "float: " << exception.what() << '\n';
}

void	ScalarPrinter::printDouble(const double &doubleNumber)
{
	if (std::isinf(doubleNumber) == true)
		std::cout << std::showpos << "double: " << doubleNumber << '\n'; 
	else
	{
		std::cout.precision(ScopeChecker::getPrecision(doubleNumber));
		std::cout << std::fixed << "double: " << doubleNumber << '\n';
	}
}

void	ScalarPrinter::printDouble(const std::exception &exception)
{
	std::cout << "double: " << exception.what() << '\n';
}