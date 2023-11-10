#include <cstring>
#include <iostream>

enum Data {NUM1, NUM2, NUM3, NUM4, NUM5};

# define SEPERATOR	"|"


int	main(void)
{
	std::string	string = "0123456789";
	std::string	other;

	other = string.substr(0, 9);
	std::cout << other << std::endl;
	return (0);
}
