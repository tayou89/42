#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include <iostream>

void	testAnimalSound(Animal **animalArray, const int arraySize);
void	showAnimalIdea(Animal *animalPTR);

int	main(void)
{
	std::string	dogIdeas[4] = { "Home", "Meat", "Sausage", "Happy" };
	std::string catIdeas[4] = { "Fish", "Mouse", "Nap", "Clean" };
	Dog			sampleDog(dogIdeas, 4); std::cout << std::endl;
	Cat			sampleCat(catIdeas, 4);	std::cout << std::endl;

	const int	arraySize = 4;
	Animal		*animalArray[arraySize] = { new Dog(), new Dog(sampleDog), 
											new Cat(), new Cat(sampleCat) };
	int			i;
	
	std::cout << std::endl;
	testAnimalSound(animalArray, arraySize);
	std::cout << std::endl;

	std::cout << "Sample dog brain address: " << sampleDog.getBrainPTR() << std::endl;
	std::cout << "Sample cat brain address: " << sampleCat.getBrainPTR() << std::endl;
	std::cout << std::endl;

	for (i = 0; i < arraySize; i++)
	{
		showAnimalIdea(animalArray[i]);
		delete animalArray[i];
		std::cout << std::endl;
	}
	return (0);
}

void	testAnimalSound(Animal **animalArray, const int arraySize)
{
	int	i;
	
	for (i = 0; i < arraySize; i++)
	{
		std::cout << "Animal Type: " << animalArray[i]->getType() << std::endl;
		animalArray[i]->makeSound();	
		std::cout << std::endl;
	}
}

void	showAnimalIdea(Animal *animalPTR)
{
	int	i;

	std::cout << "Animal type: " << animalPTR->getType() << std::endl;
	std::cout << "Animal brain address: " << animalPTR->getBrainPTR() << std::endl;
	if (animalPTR->getBrainIdeaCount() == 0)
		std::cout << "I don't have any idea." << std::endl;
	for (i = 0; i < animalPTR->getBrainIdeaCount(); i++)
		std::cout << "idea[" << i << "]: " << animalPTR->getBrainIdea(i) << std::endl;
}