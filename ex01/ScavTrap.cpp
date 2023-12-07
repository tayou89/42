#include "ScavTrap.hpp"
#include <iostream>

ScavTrap::ScavTrap(void)
{
	std::cout << name << " ScavTrap constructor is called." << std::endl;
	hitPoints = 100;
	energyPoints = 50;
	attackDamage = 20;
}

ScavTrap::~ScavTrap(void)
{
	std::cout << name << " ScavTrap destructor is called." << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &object)
	: ClapTrap(object.ClapTrap::name)
{
	std::cout << object.name << " ScavTrap copy constructor is called." << std::endl;
	*this = object;
}

ScavTrap	&ScavTrap::operator=(const ScavTrap &object)
{
	if (this == &object)
		return (*this);
	name = object.name;
	hitPoints = object.hitPoints;
	energyPoints = object.energyPoints;
	attackDamage = object.attackDamage;
	return (*this);
}

ScavTrap::ScavTrap(const std::string name)
{
	std::cout << name << " ScavTrap constructor is called." << std::endl;
	this->name = name;
	hitPoints = 100;
	energyPoints = 50;
	attackDamage = 20;
}

void	ScavTrap::attack(const std::string &target)
{
	if (hitPoints > 0 && energyPoints > 0)
	{
		std::cout << "ScavTrap " << name << " attacks " << target;
		std::cout << ", causing " << attackDamage << " points of damage!" << std::endl;
		--energyPoints;
	}
	else
		std::cout << "ScavTrap " << name << " can't attack " << target << std::endl;
}

void	ScavTrap::guardGate(void)
{
	if (hitPoints > 0 && energyPoints > 0)
	{
		std::cout << "ScavTrap " << name << " is now in gate keeper mode." << std::endl;
		--energyPoints;
	}
	else
		std::cout << "ScavTrap " << name << " can't be in gate keeper mode." << std::endl;
}
