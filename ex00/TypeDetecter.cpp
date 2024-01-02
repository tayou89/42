#include "TypeDetecter.hpp"
#include <cstdlib>
#include <sstream>

TypeDetecter::TypeDetecter(void)
	: scalarType("")
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
	scalarType = object.getScalarType();
	return (*this);
}

TypeDetecter::TypeDetecter(const std::string &cppLiteral)
{
	setScalarType(cppLiteral);
}

std::string	TypeDetecter::getScalarType(void) const
{
	return (scalarType);
}

void	TypeDetecter::setScalarType(const std::string &cppLiteral) 
{
	if (isCharLiteral(cppLiteral) == true)
		scalarType = "char";
	else if (isIntLiteral(cppLiteral) == true)
		scalarType = "int";
	else if (isFloatLiteral(cppLiteral) == true)
		scalarType = "float";
	else if (isDoubleLiteral(cppLiteral) == true)
		scalarType = "double";
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
	std::stringstream	stringStream(cppLiteral);
	int					number;
	char				character = 0;
	std::string			endString;


	stringStream >> number;
	if (stringStream.fail() == true)
		return (false);
	stringStream >> character;
	if (stringStream.fail() == true || character != '.')
		return (false);
	stringStream >> number;
	if (stringStream.fail() == true)
		return (false);
	stringStream >> endString;
	if (stringStream.fail() == true || endString != "f")
		return (false);
	if (stringStream.eof() == false)
		return (false);
	return (true);
}

bool	TypeDetecter::isDoubleLiteral(const std::string &cppLiteral)
{
	std::stringstream	stringStream(cppLiteral);
	int					number;
	char				character = 0;

	stringStream >> number;
	if (stringStream.fail() == true)
		return (false);
	stringStream >> character;
	if (stringStream.fail() == true || character != '.')
		return (false);
	stringStream >> number;
	if (stringStream.fail() == true || stringStream.eof() == false)
		return (false);
	return (true);
}