#include "HumanB.hpp"
#include <iostream>

HumanB::HumanB(const std::string name)
{
	this->name = name;
	weaponPTR = NULL;
}

void	HumanB::attack(void) const
{
	if (weaponPTR == NULL)
		std::cout << "Can't attack: " << name << " doesn't have weapon.";
	else
		std::cout << name << " attacks with their " << weaponPTR->getType();
	std::cout << std::endl;
}

void	HumanB::setWeapon(Weapon &weaponREF)
{
	weaponPTR = &weaponREF;
}
