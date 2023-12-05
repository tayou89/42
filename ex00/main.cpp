#include "ClapTrap.hpp"

int	main(void)
{
	ClapTrap	A("A");
	ClapTrap	B("B");
	ClapTrap	C(A);
	ClapTrap	D;	

	A.attack("B");
	B.takeDamage(5);
	B.attack("A");
	A.takeDamage(6);
	B.beRepaired(3);
	B.attack("A");
	A.takeDamage(6);
	A.beRepaired(4);
	A.attack("B");
	return (0);
}
