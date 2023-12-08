#include "AMateria.hpp"

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

std::string const	&getType(void) const
