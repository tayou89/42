# include "Ice.hpp"
# include <iostream>

Ice::Ice(void)
    : AMateria("ice")
{
}

Ice::~Ice(void)
{
}

Ice::Ice(const Ice &object)
    : AMateria(object.getType())
{
}

Ice &Ice::operator=(const Ice &object)
{
    if (this != &object)
        type = object.getType();
    return (*this);
}

AMateria    *Ice::clone(void) const
{
    AMateria    *newIcePTR = new Ice();

    return (newIcePTR);
}

void	Ice::use(ICharacter &target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;	
}
