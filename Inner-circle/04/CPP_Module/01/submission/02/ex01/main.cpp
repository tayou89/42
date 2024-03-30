#include "Zombie.hpp"

int	main(void)
{
	Zombie	*zombie;
	int		zombieCount = 20;
	int		i;

	zombie = zombieHorde(zombieCount, "Foo");
	for (i = 0; i < zombieCount; i++)
		zombie[i].announce();
	delete []zombie;
	return (0);
}
