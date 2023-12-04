#include "ScavTrap.hpp"
#include <iostream>

ScavTrap::ScavTrap(void)
	: hitPoints(100), energyPoints(50), attackDamage(20)
{
	std::cout << "ScavTrap default constructor is called." << std::endl;
}

ScavTrap::~ScavTrap(void)
{
	std::cout << "ScavTrap destructor is called." << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &object)
{
	std::cout << "ScavTrap copy constructor is called." << std::endl;
	*this = object;
}

ScavTrap	&ScavTrap::operator=(const ScavTrap &object)
{
	if (this == &object)
		return (*this);
	this->name = object.getName();
	this->hitPoints = object.getHitPoints();
	this->energyPoints = object.getEnergyPoints();
	this->attackDamage = object.getAttackDamage();
}

ScavTrap::ScavTrap(const std::string name)
	: name(name), hitPoints(100), energyPoints(50), attackDamage(20)
{
	std::cout << "ScavTrap " << name << " constructor is called." << std::endl;
}

void	ScavTrap::ScavTrap(void)
{
	if (hitPoints > 0 && energyPoints > 0)
	{
		std::cout << "ScavTrap " << name << " is now in gate keeper mode." << std::endl;
		--enegyPoints;
	}
	else
		std::cout << "ScavTrap " << name << " can't be in gate keeper mode." << std::endl;
}
