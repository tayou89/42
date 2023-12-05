#include "ScavTrap.hpp"

int	main(void)
{
	ScavTrap	A("A");
	ScavTrap	B("B");

	A.attack("B");
	B.takeDamage(5);
	/*
	B.attack("A");
	A.takeDamage(6);
	B.beRepaired(3);
	B.attack("A");
	A.takeDamage(6);
	A.beRepaired(4);
	A.attack("B");
	*/
	return (0);
}
