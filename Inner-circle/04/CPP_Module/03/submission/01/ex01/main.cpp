#include "ScavTrap.hpp"

int	main(void)
{
	ScavTrap	A("A");
	ScavTrap	B("B");
	ScavTrap	C(A);
	ScavTrap	D;

	A.attack("B");
	B.takeDamage(20);

	B.attack("A");
	A.takeDamage(20);
	B.beRepaired(30);
	B.guardGate();

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
