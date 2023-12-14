#include "AAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include <iostream>

int	main(void)
{
	const int	arraySize = 4;	
	AAnimal		*aAnimalPTR[arraySize];
	int			i;

	for (i = 0; i < (arraySize / 2); i++)
	{
		aAnimalPTR[i] = new Dog();	
		std::cout << std::endl;
	}
	for (; i < arraySize; i++)
	{
		aAnimalPTR[i] = new Cat();	std::cout << std::endl;
		std::cout << std::endl;
	}
	for (i = 0; i < arraySize; i++)
	{
		std::cout << "AAnimal Type: " << aAnimalPTR[i]->getType() << std::endl;
		aAnimalPTR[i]->makeSound();
		delete aAnimalPTR[i];
		std::cout << std::endl;
	}
	return (0);
}
