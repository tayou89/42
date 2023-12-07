#include "DiamondTrap.hpp"
#include <iostream>

DiamondTrap::DiamondTrap(void)
    : ClapTrap("_clap_name")
{
    std::cout << "Default DiamondTrap constructor is called." << std::endl;
    hitPoints = FragTrap::hitPoints;
    energyPoints = ScavTrap::energyPoints;
    attackDamage = FragTrap::attackDamage;
}

DiamondTrap::~DiamondTrap(void)
{
    std::cout << name << " DiamondTrap destructor is called." << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &object)
    : 	ClapTrap(object.ClapTrap::name), 
		ScavTrap(object.ScavTrap::name), 
		FragTrap(object.FragTrap::name)
{
	std::cout << object.name << " DiamondTrap copy constructor is called." << std::endl;
    *this = object;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &object)
{
	if (this == &object)
		return (*this);
	name = object.name;
	ClapTrap::name = object.ClapTrap::name;
	ScavTrap::name = object.ScavTrap::name;
	FragTrap::name = object.FragTrap::name;
	hitPoints = object.hitPoints;
	energyPoints = object.energyPoints;
	attackDamage = object.attackDamage;
	return (*this);
}

DiamondTrap::DiamondTrap(std::string name)
	: ClapTrap(name + "_clap_name")
{
	std::cout << name << " DiamondTrap constructor is called." << std::endl;
	this->name = name;
	hitPoints = FragTrap::hitPoints;
	energyPoints = ScavTrap::energyPoints;
	attackDamage = FragTrap::attackDamage;
}

void	DiamondTrap::whoAmI(void) const
{
	std::cout << "DiamondTrap name: " << name << std::endl;
	std::cout << "ClapTrap name: " << ClapTrap::name << std::endl;
}
