#include "Dog.hpp"
#include <iostream>

Dog::Dog(void)
{
	std::cout << "Dog default constructor is called." << std::endl;
	type = "Dog";
	brainPTR = new Brain();
}

Dog::~Dog(void)
{
	std::cout << "Dog destructor is called." << std::endl;
	delete brainPTR;
}

Dog::Dog(const Dog &object)
	: AAnimal()
{
	std::cout << "Dog copy constructor is called." << std::endl;
	brainPTR = new Brain();
	*this = object;
}

Dog	&Dog::operator=(const Dog &object)
{
	if (this == &object)
		return (*this);
	type = object.type;
	*brainPTR = *(object.brainPTR);
	return (*this);
}

void	Dog::makeSound(void) const
{
	std::cout << "Bark!" << std::endl;
}
