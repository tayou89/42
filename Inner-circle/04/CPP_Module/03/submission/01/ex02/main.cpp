#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int	main(void)
{
	ClapTrap	A("A");
	ScavTrap	B("B");
	FragTrap	C("C");
	int			i;

	A.attack("B");
	B.takeDamage(A.getAttackDamage());

	B.attack("A");
	A.takeDamage(B.getAttackDamage());

	for (i = 0; i < 4; i++)
	{
		C.attack("B");
		B.takeDamage(C.getAttackDamage());
		B.attack("C");
		C.takeDamage(B.getAttackDamage());
	}
	
	B.beRepaired(50);
	C.beRepaired(50);
	C.highFivesGuys();
	return (0);
}
