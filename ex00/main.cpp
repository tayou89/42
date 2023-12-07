#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>

int	main(void)
{
	const Animal *animalPTR = new Animal();
	const Animal *dogPTR = new Dog();
	const Animal *catPTR = new Cat();
	const WrongAnimal *wrongAnimalPTR = new WrongAnimal();
	const WrongAnimal *wrongCatPTR = new WrongCat();

	std::cout << "Object type: " << animalPTR->getType() << std::endl;
	animalPTR->makeSound();

	std::cout << "Object type: " << dogPTR->getType() << std::endl;
	dogPTR->makeSound();

	std::cout << "Object type: " << catPTR->getType() << std::endl;
	catPTR->makeSound();

	std::cout << "Object type: " << wrongAnimalPTR->getType() << std::endl;
	wrongAnimalPTR->makeSound();

	std::cout << "Object type: " << wrongCatPTR->getType() << std::endl;
	wrongCatPTR->makeSound();

	delete animalPTR;
	delete dogPTR;
	delete catPTR;
	return (0);
}
