#include "DiamondTrap.hpp"

int	main(void)
{
	DiamondTrap	A("A");
	DiamondTrap	B(A);

	A.attack("B");
	A.takeDamage(30);
	A.beRepaired(30);
	A.guardGate();
	A.highFivesGuys();
	A.whoAmI();
	return (0);
}
