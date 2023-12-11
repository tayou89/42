#include "Dog.hpp"
#include <iostream>

Dog::Dog(void)
{
	std::cout << "Dog default constructor is called." << std::endl;
	type = "Dog";
}

Dog::~Dog(void)
{
	std::cout << "Dog destructor is called." << std::endl;
}

Dog::Dog(const Dog &object)
	: Animal()
{
	std::cout << "Dog copy constructor is called." << std::endl;
	*this = object;
}

Dog	&Dog::operator=(const Dog &object)
{
	if (this == &object)
		return (*this);
	type = object.type;
	return (*this);
}

void	Dog::makeSound(void) const
{
	std::cout << "Bark!" << std::endl;
}
