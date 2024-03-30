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
	: Animal()
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

Cat::Cat(const std::string *ideas, const int ideaCount)
{
	int	i;

	std::cout << "Cat constructor is called." << std::endl;
	type = "Cat";
	brainPTR = new Brain();
	for (i = 0; i < ideaCount; i++)
		setBrainIdea(ideas[i]);
}

void	Cat::makeSound(void) const
{
	std::cout << "Meow~" << std::endl;
}

void	Cat::setBrainIdea(const std::string idea)
{
	brainPTR->setIdea(idea);	
}

std::string	Cat::getBrainIdea(const int ideaIndex) const
{
	return (brainPTR->getIdea(ideaIndex));
}

int	Cat::getBrainIdeaCount(void) const
{
	return (brainPTR->getIdeaCount());
}

void	*Cat::getBrainPTR(void) const
{
	return (brainPTR);
}