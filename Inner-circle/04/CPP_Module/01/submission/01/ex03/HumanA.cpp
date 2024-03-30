#include "HumanA.hpp"
#include <iostream>

HumanA::HumanA(const std::string name, Weapon &club)
	:name(name), weaponREF(club)
{
}

void	HumanA::attack(void) const
{
	std::cout << name << " attacks with their " << weaponREF.getType() << std::endl;
}
