#include <sstream>
#include <iostream>

#define TRUE	1
#define	FALSE	0
/*
int	main(void)
{
	std::string			string;
	int					number;
	std::stringstream	stringstream;

	std::cout << "string: ";
	std::getline(std::cin, string);
	while (string != "EXIT")
	{
		stringstream.str(string);
		stringstream >> number;
		std::cout << "number: " << number << std::endl;
		stringstream >> string;
		std::cout << "string: " << string << std::endl;
		if (stringstream.fail() == TRUE)
			std::cout << "stringstream.fail() == TRUE.\n";
		stringstream.clear();
		number = 0;
		std::cout << "string: ";
		std::getline(std::cin, string);
	}
	return (0);
}
*/

int	main(void)
{
	std::string string;

	std::cout << "string: ";
	std::getline(std::cin, string);
	std::cout << "stirng: " << string << std::endl;
	return (0);
}
