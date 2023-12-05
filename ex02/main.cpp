#include "ScavTrap.hpp"

int	main(void)
{

	B.attack("A");
	A.takeDamage(20);

	B.attack("A");
	A.takeDamage(20);

	B.attack("A");
	A.takeDamage(20);

	B.attack("A");
	A.takeDamage(20);

	A.beRepaired(30);
	A.attack("B");
	A.guardGate();
	return (0);
}
