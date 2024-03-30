#include "Brain.hpp"
#include <iostream>

Brain::Brain(void)
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
	int	stringSize = sizeof(object.ideas) / sizeof(object.ideas[0]); 
	int	i;

	if (this == &object)
		return (*this);
	for (i = 0; i < stringSize; i++)
		ideas[i] = object.ideas[i];
	return (*this);
}
