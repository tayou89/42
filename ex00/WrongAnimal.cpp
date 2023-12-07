#include "WrongAnimal.hpp"
#include <iostream>

WrongAnimal::WrongAnimal(void)
	: type("WrongAnimal")
{
	std::cout << "WrongAnimal default constructor is called." << std::endl;
}

WrongAnimal::~WrongAnimal(void)
{
	std::cout << "WrongAnimal destructor is called." << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &object)
{
	std::cout << "WrongAnimal copy constructor is called." << std::endl;
	*this = object;
}

WrongAnimal	&WrongAnimal::operator=(const WrongAnimal &object)
{
	if (this == &object)
		return (*this);
	type = object.type;
	return (*this);
}

void	WrongAnimal::makeSound(void) const
{
	std::cout << "Oops! I don't know which animal I am." << std::endl;
}

std::string	WrongAnimal::getType(void) const
{
	return (type);
}
