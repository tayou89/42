#include "FragTrap.hpp"
#include <iostream>

FragTrap::FragTrap(void)
{
	std::cout << name << " FragTrap constructor is called." << std::endl;
	hitPoints = 100;
	energyPoints = 100;
	attackDamage = 30;
}

FragTrap::~FragTrap(void)
{
	std::cout << name << " FragTrap destructor is called." << std::endl;
}

FragTrap::FragTrap(const FragTrap &object)
	: ClapTrap(object.ClapTrap::name)
{
	std::cout << object.name << " FragTrap copy constructor is called." << std::endl;
	*this = object;
}

FragTrap	&FragTrap::operator=(const FragTrap &object)
{
	if (this == &object)
		return (*this);
	name = object.name;
	hitPoints = object.hitPoints;
	energyPoints = object.energyPoints;
	attackDamage = object.attackDamage;
	return (*this);
}

FragTrap::FragTrap(const std::string name)
{
	std::cout << name << " FragTrap constructor is called." << std::endl;
	this->name = name;
	hitPoints = 100;
	energyPoints = 100;
	attackDamage = 30;
}

void	FragTrap::highFivesGuys(void)
{
	if (hitPoints > 0 && energyPoints > 0)
	{
		std::cout << "FragTrap " << name << " High-Fives Guys!" << std::endl;
		--energyPoints;
	}
	else
	{
		if (hitPoints <= 0)
			std::cout << "FragTrap " << name << " doesn't have a hit point.\n";
		if (energyPoints <= 0)
			std::cout << "FragTrap " << name << " doesn't have an energy point.\n";
		std::cout << "FragTrap " << name << " can't do High-Five." << std::endl;
	}
}
