#include "AAnimal.hpp"
#include <iostream>

AAnimal::AAnimal(void)
	: type("AAnimal")
{
	std::cout << "AAnimal default constructor is called." << std::endl;
}

AAnimal::~AAnimal(void)
{
	std::cout << "AAnimal destructor is called." << std::endl;
}

AAnimal::AAnimal(const AAnimal &object)
{
	std::cout << "AAnimal copy constructor is called." << std::endl;
	*this = object;
}

AAnimal	&AAnimal::operator=(const AAnimal &object)
{
	if (this == &object)
		return (*this);
	type = object.type;
	return (*this);
}

std::string	AAnimal::getType(void) const
{
	return (type);
}