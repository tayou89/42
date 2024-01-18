#include "RPN.hpp"
#include <iostream>

int	main(int argc, char *argv[])
{
	(void) argc;
	try
	{
		RPN	object(argv[1]);
		int	calculationResult = object.calculateRPN();

		std::cout << "Calculation result: " << calculationResult << '\n';
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return (0);
}