#include "Animal.hpp"
#include <iostream>

Animal::Animal(void)
	: type("Animal")
{
	std::cout << "Animal default constructor is called." << std::endl;
}

Animal::~Animal(void)
{
	std::cout << "Animal destructor is called." << std::endl;
}

Animal::Animal(const Animal &object)
{
	std::cout << "Animal copy constructor is called." << std::endl;
	*this = object;
}

Animal	&Animal::operator=(const Animal &object)
{
	if (this == &object)
		return (*this);
	type = object.type;
	return (*this);
}

void	Animal::makeSound(void) const
{
	std::cout << "Oops! I don't know which animal I am." << std::endl;
}

std::string	Animal::getType(void) const
{
	return (type);
}