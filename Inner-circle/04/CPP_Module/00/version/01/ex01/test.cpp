#include <string>
#include <iostream>

void	get_string(std::string	*string);

int	main(void)
{
	std::string	string;

	std::cin >> string;
	if (string[0] == ' ')
		std::cout << "string[0] is space.\n";
	if (string[0] == '\0')
		std::cout << "string[0] is null character.\n";
	std::cout << string;
	return (0);
}
