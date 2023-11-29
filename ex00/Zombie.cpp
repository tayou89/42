#include "Zombie.hpp"

Zombie::Zombie(std::string name)
	: name(name)
{
}

void	Zombie::announce(void)
{
	std::cout << name << ": " << "BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::~Zombie(void)
{
	std::cout << name << " is destructed.\n";
}
