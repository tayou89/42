#include <iostream>
#include <sstream>
#include <cstdlib>
#include <typeinfo>

int	main(int argc, char *argv[])
{
	std::stringstream	stringStream;
	std::string			string;
	int					number;
	char				character = '\n';

	number = character;
	std::cout << "number: " << number << '\n';
	return (0);
	if (argc != 2)
		return (0);
	string = argv[1];
	stringStream << string;
	stringStream >> number;
	character = number;
	std::cout << "number: " << number << '\n';
	std::cout << "character: " << character << '\n';
	return (0);
}