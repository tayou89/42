#include <iostream>
#include <sstream>

int	main(int argc, char *argv[])
{
	std::string 		string = argv[1];
	std::stringstream	stringStream;
	double				number;
	char				character;
	std::string			restString;
	//char				checkString[100];
	//int					i;

	std::cout << number << '\n';
	return (0);

	if (argc != 2)
		return (0);
	stringStream << string;
	//i = 0;
	stringStream >> number;
	if (stringStream.fail() == true)
	{
		std::cout << "string1 is not a float\n";
		return (0);
	}
	stringStream >> character;
	if (stringStream.fail() == true || character != '.')
	{	
		std::cout << "string2 is not a flaot\n";
		return (0);
	}
	stringStream >> number;
	if (stringStream.fail() == true)
	{
		std::cout << "string3 is not a flaot\n";
		return (0);
	}
	stringStream >> restString;
	if (stringStream.fail() == true || restString != "f")
	{
		std::cout << "string4 is not a flaot\n";
		return (0);
	}
	if (stringStream.eof() == true)
		std::cout << "string is a float.\n";
	else
		std::cout << "string5 is not a float.\n";
	return (0);
}