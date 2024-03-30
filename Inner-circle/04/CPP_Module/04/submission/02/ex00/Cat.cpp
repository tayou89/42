#include "Cat.hpp"
#include <iostream>

Cat::Cat(void)
{
	std::cout << "Cat default constructor is called." << std::endl;
	type = "Cat";
}

Cat::~Cat(void)
{
	std::cout << "Cat destructor is called." << std::endl;
}

Cat::Cat(const Cat &object)
	: Animal()
{
	std::cout << "Cat copy constructor is called." << std::endl;
	*this = object;
}

Cat	&Cat::operator=(const Cat &object)
{
	if (this == &object)
		return (*this);
	type = object.type;
	return (*this);
}

void	Cat::makeSound(void) const
{
	std::cout << "Meow~" << std::endl;
}