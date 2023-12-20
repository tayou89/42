#include <iostream>
#include <limits>
#include <cstdlib>
#include <iomanip>

int	main(int argc, char *argv[])
{
	double	doubleNumber;
	float	floatNumber;
	int		integer;
	char	*nextString;

	if (argc <= 1)
		return (0);
	doubleNumber = std::strtod(argv[1], &nextString);
	floatNumber = static_cast<float>(doubleNumber);
	integer = static_cast<int>(doubleNumber);
	std::cout << "argv[1]: " << argv[1] << '\n';
	std::cout << std::setprecision(5) << "doubleNumber: " << doubleNumber << '\n';
	std::cout << std::setprecision(5) << "floatNumber: " << floatNumber << '\n';
	std::cout << std::setprecision(5) << "integer: " << integer << '\n';
	if (nextString[0] == '\0')
		std::cout << "nextString is empty.\n";
	else
		std::cout << "nextString: " << nextString << '\n';
	return (0);
}