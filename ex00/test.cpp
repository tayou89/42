#include <iostream>
#include <sstream>
#include <cstdlib>
#include <typeinfo>

int	main(void)
{
	long long	number = 99999999999;
	int			integer = static_cast<int>(number);

	std::cout << "integer: " << integer << '\n';
	return (0);
}