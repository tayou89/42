#include <fstream>
#include <iostream>

int	main(void)
{
	std::ifstream	inputStream;
	std::ofstream	outputStream;
	std::string		string;
	int				foundIndex = 0;
	int				i = 0;
	int				j = 0;

	inputStream.open("aaa.txt");
	outputStream.open("result.txt");
	while (inputStream.eof() == false)
	{
		std::getline(inputStream, string);
		while (string.find("aaa", i) != std::string::npos)
		{
			foundIndex = string.find("aaa", i);
			if (foundIndex != std::string::npos)
			{
				std::cout << "foundIndex: " << foundIndex << std::endl;
				string.erase(foundIndex, 3);
				string.insert(foundIndex, "ddddd");
				std::cout << "string: " << string << std::endl;
				i = foundIndex + 5;
			}
		}
		if (string != "")
			outputStream << string << '\n';
	}
	return (0);
}
