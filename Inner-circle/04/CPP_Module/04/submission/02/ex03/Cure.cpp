#include "Cure.hpp"
#include <iostream> 

Cure::Cure(void)
    : AMateria("cure")
{
}

Cure::~Cure(void)
{
}

Cure::Cure(const Cure &object)
    : AMateria(object.getType())
{
}

Cure &Cure::operator=(const Cure &object)
{
    if (this != &object)
        type = object.getType();
    return (*this);
}

AMateria    *Cure::clone(void) const
{
    AMateria    *newCurePTR = new Cure();

    return (newCurePTR);
}

void	Cure::use(ICharacter &target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}