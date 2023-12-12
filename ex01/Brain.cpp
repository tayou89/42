#include "Brain.hpp"
#include <iostream>

Brain::Brain(void)
	: ideaCount(0)
{
	std::cout << "Brain default constructor is called." << std::endl;
}

Brain::~Brain(void)
{
	std::cout << "Brain destructor is called." << std::endl;
}

Brain::Brain(const Brain &object)
{
	std::cout << "Brain copy constructor is called." << std::endl;
	*this = object;
}

Brain	&Brain::operator=(const Brain &object)
{
	int	i;

	ideaCount = object.getIdeaCount();
	if (this == &object)
		return (*this);
	for (i = 0; i < maxIdeaCount; i++)
		ideas[i] = object.ideas[i];
	return (*this);
}

std::string	Brain::getIdea(const int ideaIndex) const
{
	if (ideaIndex < ideaCount)
		return (ideas[ideaIndex]);
	else
		return ("");
}

void	Brain::setIdea(const std::string idea)
{
	if (ideaCount < maxIdeaCount)
		ideas[ideaCount++] = idea;
	else
		std::cout << "Brain is already full of ideas." << std::endl;
}

int	Brain::getIdeaCount(void) const
{
	return (ideaCount);
}