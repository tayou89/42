#include "TypeDetecter.hpp"
#include "Converter.hpp"
#include <cstdlib>
#include <sstream>

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
	char		*string	= nullptr;
	std::string	restString;	

	std::strtod(cppLiteral.c_str(), &string);
	restString = const_cast<const char *>(string);
	if (restString != "f")
		return (false);
	if (cppLiteral.find('.') == std::string::npos)
		return (false);
	return (true);
}

bool	TypeDetecter::isDoubleLiteral(const std::string &cppLiteral)
{
	char	*restString = nullptr;

	std::strtod(cppLiteral.c_str(), &restString);
	if (restString[0] != '\0')
		return (false);
	if (cppLiteral.find('.') == std::string::npos)
		return (false);
	return (true);
}