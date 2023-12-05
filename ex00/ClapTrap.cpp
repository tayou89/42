#include "ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap(void)
	: hitPoints(10), energyPoints(10), attackDamage(0)
{
	std::cout << "Default constructor is called." << std::endl;
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "Destructor " << name << " is called." << std::endl;
}

ClapTrap::ClapTrap(std::string name)
	: name(name), hitPoints(10), energyPoints(10), attackDamage(0)
{
	std::cout << "Constructor " << name << " is called." << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &object)
{
	std::cout << "Copy constructor is called." << std::endl;
	*this = object;
}

ClapTrap	&ClapTrap::operator=(const ClapTrap &object)
{
	if (this == &object)
		return (*this);
	name = object.name;
	hitPoints = object.hitPoints;
	energyPoints = object.energyPoints;
	attackDamage = object.attackDamage;
	return (*this);
}

void	ClapTrap::attack(const std::string &target)
{
	if (hitPoints > 0 && energyPoints > 0)
	{
		std::cout << "ClapTrap " << name << " attacks " << target;
		std::cout << ", causing " << attackDamage << " points of damage!" << std::endl;
		--energyPoints;
	}
	else
		std::cout << "ClapTrap " << name << " can't attack " << target << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << "Clap Trap " << name << " takes " << amount << " damage." << std::endl;
	hitPoints -= amount;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (hitPoints > 0 && energyPoints > 0)
	{
		std::cout << "Clap Trap " << name << " is repaired, ";
		std::cout << "getting " << amount << " hit point(s)." << std::endl;
		hitPoints += amount;
		--energyPoints;
	}
	else
		std::cout << "Clap Trap " << name << " can't be repaired." << std::endl;
}
