#include "AMateria.hpp"
#include <iostream>

AMateria::AMateria(void)
{
}

AMateria::~AMateria(void)
{
}

AMateria::AMateria(const AMateria &object)
{
	*this = object;
}

AMateria	&AMateria::operator=(const AMateria &object)
{
	if (this != &object)
		type = object.getType();
	return (*this);
}

AMateria::AMateria(std::string const &type)
	: type(type)
{
}

std::string const	&AMateria::getType(void) const
{
	return (type);
}

void	AMateria::use(ICharacter &target)	
{
	std::cout << "I don't what to do for " << target.getName() << std::endl;
}