#include "ScalarPrinter.hpp"
#include <iostream>
#include <cmath>
#include <iomanip>

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

void	ScalarPrinter::printChar(const char &character)
{
	std::cout << "char: \'" << character << "\'\n"; 
}

void	ScalarPrinter::printInt(const int &integer)
{
	std::cout << "Int: " << integer << '\n';
}

void	ScalarPrinter::printFloat(const float &floatNumber)
{
	if (std::isinf(floatNumber) == true)
		std::cout << std::showpos << "float: " << floatNumber << "f\n";
	else if (std::isnan(floatNumber) == true)
		std::cout << "float: " << floatNumber << "f\n";
	else
	{
		float	integerPart;
		float	fractionalPart = std::modf(floatNumber, &integerPart);

		std::cout << std::fixed;
		if (fractionalPart == 0)
			std::cout.precision(1);
		std::cout << "float: " << floatNumber << "f\n";
	}
}

void	ScalarPrinter::printDouble(const double &doubleNumber)
{
	if (std::isinf(doubleNumber) == true)
		std::cout << std::showpos << "double: " << doubleNumber << '\n';
	else if (std::isnan(doubleNumber) == true)
		std::cout << "double: " << doubleNumber << '\n';
	else
	{
	//	double	integerPart;
	//	double	fractionalPart = std::modf(doubleNumber, &integerPart);
		//int		maxPrecision = std::numeric_limits<double>::digits10 + 1;
		//int		minPrecision = std::cout.precision();

		std::cout << std::fixed;
		std::cout << std::cout.precision() << '\n';
		//std::cout << "minprecision: " << minPrecision << '\n';
	//	if (fractionalPart == 0)
			//std::cout << std::setprecision(minPrecision) << "double: " << doubleNumber << '\n';
			std::cout << "double: " << doubleNumber << '\n';
	//	else
		////	std::cout << std::setprecision(maxPrecision) << "double: " << doubleNumber << '\n';
	}
}

void	ScalarPrinter::printChar(const std::exception &exception)
{
	std::cout << "char: " << exception.what() << std::endl;
}

void	ScalarPrinter::printInt(const std::exception &exception)
{
	std::cout << "int: " << exception.what() << std::endl;
}

void	ScalarPrinter::printFloat(const std::exception &exception)
{
	std::cout << "float: " << exception.what() << std::endl;
}

void	ScalarPrinter::printDouble(const std::exception &exception)
{
	std::cout << "double: " << exception.what() << std::endl;
}