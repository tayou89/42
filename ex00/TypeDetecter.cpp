#include "TypeDetecter.hpp"
#include "Converter.hpp"
#include <cstdlib>
#include <sstream>
#include <cmath>

TypeDetecter::TypeDetecter(void)
{
}

TypeDetecter::~TypeDetecter(void)
{
}

TypeDetecter::TypeDetecter(const TypeDetecter &object)
{
	*this = object;
}

TypeDetecter	&TypeDetecter::operator=(const TypeDetecter &object)
{
	if (this == &object)
		return (*this);
	return (*this);
}

std::string	TypeDetecter::getScalarType(const std::string &cppLiteral) throw (std::exception)
{
	if (isCharLiteral(cppLiteral) == true)
		return ("char");
	else if (isIntLiteral(cppLiteral) == true)
		return ("int");
	else if (isFloatLiteral(cppLiteral) == true)
		return ("float");
	else if (isDoubleLiteral(cppLiteral) == true)
		return ("double");
	else
		throw (Converter::UnconvertableException());
}

bool	TypeDetecter::isCharLiteral(const std::string &cppLiteral)
{
	if (cppLiteral.size() == 3 && cppLiteral[0] == '\'' && cppLiteral[2] == '\'')
		return (true);
	else
		return (false);
}

bool	TypeDetecter::isIntLiteral(const std::string &cppLiteral)
{
	std::stringstream	stringStream(cppLiteral);
	int					integer;

	stringStream >> integer;
	if (stringStream.fail() == true)
		return (false);
	if (stringStream.eof() == false)
		return (false);
	return (true);
}

bool	TypeDetecter::isFloatLiteral(const std::string &cppLiteral)
{
	char		*string	= NULL;
	std::string	restString;	
	float		floatNumber = 
				static_cast<float>(std::strtod(cppLiteral.c_str(), &string));

	restString = const_cast<const char *>(string);
	if (restString != "f")
		return (false);
	if (!std::isnan(floatNumber) && !std::isinf(floatNumber))
	{
		if (cppLiteral.find('.') == std::string::npos)
			return (false);
	}
	return (true);
}

bool	TypeDetecter::isDoubleLiteral(const std::string &cppLiteral)
{
	char	*restString = NULL;
	double	doubleNumber = std::strtod(cppLiteral.c_str(), &restString);

	if (restString[0] != '\0')
		return (false);
	if (!std::isnan(doubleNumber) && !std::isinf(doubleNumber))
	{
		if (cppLiteral.find('.') == std::string::npos)
			return (false);
	}
	return (true);
}