#include <iostream>
#include <limits>
#include <cstdlib>
#include <iomanip>
#include <cmath>

int	main(int argc, char *argv[])
{
	double		doubleNumber;
	float		floatNumber;
	int			integer;
	char		character;
	char		*nextString;
	const std::string	string = argv[1];

	if (argc <= 1)
		return (0);
	doubleNumber = std::strtod(argv[1], &nextString);
	floatNumber = static_cast<float>(doubleNumber);
	integer = static_cast<int>(doubleNumber);
	character = static_cast<char>(doubleNumber);
	std::cout << "argv[1]: " << argv[1] << '\n';
	std::cout << std::fixed;
	//std::cout.precision(1);
	std::cout << "doubleNumber: " << doubleNumber << '\n';
	std::cout << "floatNumber: " << floatNumber << '\n';
	std::cout << "integer: " << integer << '\n';
	std::cout << "character: \'" << character << "\'\n";
	if (nextString[0] == '\0')
		std::cout << "nextString is empty.\n";
	else
		std::cout << "nextString: " << nextString << '\n';
	return (0);
}
/*
int	main(void)
{
	float	floatNumber = 123.00f;
	//float	integerPart;
	float	fractionalPart =  std::modf(floatNumber, NULL);

	std::cout << "floatNumber: " << floatNumber << '\n';
	//std::cout << "integerPart: " << integerPart << '\n';
	std::cout << "fractionalPart: " << fractionalPart << '\n';
	return (0);
}
*/