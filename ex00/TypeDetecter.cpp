#include "TypeDetecter.hpp"
#include <cstdlib>

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
	if (this != &object)
		return (*this);
	return (*this);
}

std::string	TypeDetecter::getScalarType(const std::string &cppLiteral)
{
	std::string	scalarType("");
	char		*restString = nullptr;

	if (cppLiteral.size() == 3 && cppLiteral[0] == '\'' && cppLiteral[3] == '\'')
		scalarType = "char";
	else
	{
		std::strtod(cppLiteral.c_str()	
	}
	
}