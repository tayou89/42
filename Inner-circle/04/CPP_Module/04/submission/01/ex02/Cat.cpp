#include "Cat.hpp"
#include <iostream>

Cat::Cat(void)
{
	std::cout << "Cat default constructor is called." << std::endl;
	type = "Cat";
	brainPTR = new Brain();
}

Cat::~Cat(void)
{
	std::cout << "Cat destructor is called." << std::endl;
	delete brainPTR;
}

Cat::Cat(const Cat &object)
	: AAnimal()
{
	std::cout << "Cat copy constructor is called." << std::endl;
	brainPTR = new Brain();
	*this = object;
}

Cat	&Cat::operator=(const Cat &object)
{
	if (this == &object)
		return (*this);
	type = object.type;
	*brainPTR = *(object.brainPTR); 
	return (*this);
}

void	Cat::makeSound(void) const
{
	std::cout << "Meow~" << std::endl;
}
