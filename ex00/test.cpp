#include <iostream>
#include <sstream>
#include <cstdlib>
#include <typeinfo>
#include <limits>

int	main(void)
{
	std::cout << "size: " << sizeof(std::numeric_limits<char>::max()) << '\n';
	return (0);
}