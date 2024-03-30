#include "WrongCat.hpp"
#include <iostream>

WrongCat::WrongCat(void)
{
	std::cout << "WrongCat default constructor is called." << std::endl;
	type = "WrongCat";
}

WrongCat::~WrongCat(void)
{
	std::cout << "WrongCat destructor is called." << std::endl;
}

WrongCat::WrongCat(const WrongCat &object)
	: WrongAnimal()
{
	std::cout << "WrongCat copy constructor is called." << std::endl;
	*this = object;
}

WrongCat	&WrongCat::operator=(const WrongCat &object)
{
	if (this == &object)
		return (*this);
	type = object.type;
	return (*this);
}

void	WrongCat::makeSound(void) const
{
	std::cout << "Meow~" << std::endl;
}
