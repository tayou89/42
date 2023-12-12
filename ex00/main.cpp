#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>

int	main(void)
{
	const Animal *animalPTR = new Animal();					std::cout << std::endl;
	const Animal *dogPTR = new Dog();						std::cout << std::endl;
	const Animal *catPTR = new Cat();						std::cout << std::endl;
	const WrongAnimal *wrongAnimalPTR = new WrongAnimal();	std::cout << std::endl;
	const WrongAnimal *wrongCatPTR = new WrongCat();		std::cout << std::endl;

	std::cout << "Object type: " << animalPTR->getType() << std::endl;
	animalPTR->makeSound();
	std::cout << std::endl;

	std::cout << "Object type: " << dogPTR->getType() << std::endl;
	dogPTR->makeSound();
	std::cout << std::endl;

	std::cout << "Object type: " << catPTR->getType() << std::endl;
	catPTR->makeSound();
	std::cout << std::endl;

	std::cout << "Object type: " << wrongAnimalPTR->getType() << std::endl;
	wrongAnimalPTR->makeSound();
	std::cout << std::endl;

	std::cout << "Object type: " << wrongCatPTR->getType() << std::endl;
	wrongCatPTR->makeSound();
	std::cout << std::endl;

	delete animalPTR;		std::cout << std::endl;
	delete dogPTR;			std::cout << std::endl;
	delete catPTR;			std::cout << std::endl;
	delete wrongAnimalPTR;	std::cout << std::endl;
	delete wrongCatPTR;		std::cout << std::endl;
	return (0);
}
