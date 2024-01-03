#include "ScopeChecker.hpp"
#include <limits>
#include <cmath>

ScopeChecker::ScopeChecker(void)
{
}

ScopeChecker::~ScopeChecker(void)
{
}

ScopeChecker::ScopeChecker(const ScopeChecker &object)
{
	*this = object;
}

ScopeChecker	&ScopeChecker::operator=(const ScopeChecker &object)
{
	if (this == &object)
		return (*this);
	return (*this);
}

bool	ScopeChecker::isCharScope(const int &integer)
{
	if (integer >= std::numeric_limits<char>::min() &&
		integer <= std::numeric_limits<char>::max())
		return (true);
	else
		return (false);
}

bool	ScopeChecker::isCharScope(const float &floatNumber)
{
	if (std::isnan(floatNumber) == true || std::isinf(floatNumber) == true)
		return (false);
	if (floatNumber >= static_cast<float>(std::numeric_limits<char>::min()) &&
		floatNumber <= static_cast<float>(std::numeric_limits<char>::max()))
		return (true);
	else
		return (false);
}

bool	ScopeChecker::isCharScope(const double &doubleNumber)
{
	if (std::isnan(doubleNumber) == true || std::isinf(doubleNumber) == true)
		return (false);
	if (doubleNumber >= static_cast<double>(std::numeric_limits<char>::min()) &&
		doubleNumber <= static_cast<double>(std::numeric_limits<char>::max()))
		return (true);
	else
		return (false);
}

bool	ScopeChecker::isDisplayableChar(const char &character)
{
	if (character > 31 && character < 127)
		return (true);
	else
		return (false);
}

bool	ScopeChecker::isIntScope(const float &floatNumber)
{
	if (std::isnan(floatNumber) == true || std::isinf(floatNumber) == true)
		return (false);
	if (floatNumber >= static_cast<float>(std::numeric_limits<int>::min()) &&
		floatNumber <= static_cast<float>(std::numeric_limits<int>::max()))
		return (true);
	else
		return (false);
}

bool	ScopeChecker::isIntScope(const double &doubleNumber)
{	
	if (std::isnan(doubleNumber) == true || std::isinf(doubleNumber) == true)
		return (false);
	if (doubleNumber >= static_cast<double>(std::numeric_limits<int>::min()) &&
		doubleNumber <= static_cast<double>(std::numeric_limits<int>::max()))
		return (true);
	else
		return (false);
}