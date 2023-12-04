#include "ScavTrap.hpp"

int	main(void)
{
	ScavTrap	A("A");
	ScavTrap	B("B");

	A.setAttackDamage(4);
	B.setAttackDamage(3);

	A.attack("B");
	B.takeDamage(A.getAttackDamage());
	B.attack("A");
	A.takeDamage(B.getAttackDamage());
	B.beRepaired(3);
	B.attack("A");
	A.takeDamage(B.getAttackDamage());
	B.attack("A");
	A.takeDamage(B.getAttackDamage());
	B.attack("A");
	A.takeDamage(B.getAttackDamage());
	A.beRepaired(4);
	A.attack("B");
	return (0);
}
