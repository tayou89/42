#include "ScalarConverter.hpp"

int	main(int argc, char *argv[])
{
	if (argc != 2)
		return (0);
	ScalarConverter::convert(static_cast<const char *>(argv[1]));
	return (0);
}