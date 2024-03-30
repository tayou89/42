#include "Zombie.hpp"
#include <sstream>

Zombie	*zombieHorde(int N, std::string name)
{
	Zombie		*zombie = new Zombie[N];
	int			i;

	for (i = 0; i < N; i++)
		zombie[i].SetName(name + IntToString(i + 1)); 	
	return (zombie);
}

std::string	IntToString(int number)
{
	std::stringstream	stringStream;
	std::string			string;

	stringStream << number;
	stringStream >> string;
	stringStream.clear();
	stringStream.str("");
	return (string);
}
