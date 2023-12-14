#include "ICharacter.hpp"

ICharacter::ICharacter(void)
{
}

ICharacter::~ICharacter(void)
{
}

ICharacter::ICharacter(const ICharacter &object)
{
	*this = object;
}

ICharacter	&ICharacter::operator=(const ICharacter &object)
{
	if (this == &object)
		return (*this);
	return (*this);
}
