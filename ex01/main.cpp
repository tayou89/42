#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include <iostream>

int	main(void)
{
	const int	arraySize = 4;	
	Animal		*animalPTR[arraySize];
	int			i;

	atexit(leaks);
	for (i = 0; i < (arraySize / 2); i++)
		animalPTR[i] = new Dog();
	for (; i < arraySize; i++)
		animalPTR[i] = new Cat();
	std::cout << std::endl;

	for (i = 0; i < arraySize; i++)
	{
		std::cout << "Animal Type: " << animalPTR[i]->getType() << std::endl;
		animalPTR[i]->makeSound();
		delete animalPTR[i];
		std::cout << std::endl;
	}
	return (0);
}
