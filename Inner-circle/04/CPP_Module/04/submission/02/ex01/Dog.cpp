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
	: Animal()
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

Dog::Dog(const std::string *ideas, const int ideaCount)
{
	int	i;

	std::cout << "Dog constructor is called." << std::endl;
	type = "Dog";
	brainPTR = new Brain();
	for (i = 0; i < ideaCount; i++)
		setBrainIdea(ideas[i]);
}

void	Dog::makeSound(void) const
{
	std::cout << "Bark!" << std::endl;
}

void	Dog::setBrainIdea(const std::string idea)
{
	brainPTR->setIdea(idea);	
}

std::string	Dog::getBrainIdea(const int ideaIndex) const
{
	return (brainPTR->getIdea(ideaIndex));
}

int	Dog::getBrainIdeaCount(void) const
{
	return (brainPTR->getIdeaCount());
}

void	*Dog::getBrainPTR(void) const
{
	return (brainPTR);
}