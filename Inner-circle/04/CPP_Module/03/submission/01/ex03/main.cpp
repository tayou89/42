#include "DiamondTrap.hpp"
#include <iostream>

int	main(void)
{
	DiamondTrap	A("A");
	DiamondTrap	B("B");
	DiamondTrap	C(A);
	
	std::cout << std::endl;
	A.attack("B");
	A.takeDamage(30);
	A.beRepaired(30);
	A.guardGate();
	A.highFivesGuys();
	A.whoAmI();

	A = B;
	std::cout << "\nA = B is occured.\n" << std::endl;

	A.attack("B");
	A.takeDamage(30);
	A.beRepaired(30);
	A.guardGate();
	A.highFivesGuys();
	A.whoAmI();
	std::cout << std::endl;
	return (0);
}
