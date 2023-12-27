#include <iostream>
#include <sstream>

int	main(int argc, char *argv[])
{
	std::stringstream	stringStream;
	std::string			string;
	int					data;

	if (argc != 2)
		return (0);
	string = static_cast<const char *>(argv[1]);
	stringStream << string;
	stringStream >> data;
	if (stringStream.fail() == true)
		std::cout << "stringStream.fail() == true.\n";
	else
		std::cout << "data: " << data << '\n';
	if (stringStream.eof() == true)
		std::cout << "stringStream.eof() == true.\n";
	else
	{
		std::cout << "stringStream.eof() == false.\n";
		stringStream >> string;
		std::cout << "string: " << string << '\n';

	}
	return (0);
}