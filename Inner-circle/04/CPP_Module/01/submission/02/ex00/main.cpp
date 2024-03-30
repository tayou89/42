#include "Zombie.hpp"

int	main(void)
{
	Zombie	*heapZombie = newZombie("HeapZombie");
	Zombie	stackZombie("StackZombie1");

	heapZombie->announce();
	delete heapZombie;
	stackZombie.announce();
	randomChump("StackZombie2");
	return (0);
}
