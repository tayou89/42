#include "RPN.hpp"
#include <iostream>
#include <sstream>

int	main(void)
{
	std::stringstream	stringStream("   abc    ");
	std::string			string;

	stringStream >> string;
	std::cout << "string: " << string << '\n';

	return (0);
}