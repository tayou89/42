#include "Harl.hpp"
#include <iostream>

int		DefineComplainType(std::string complain[4], std::string userInput);
void	PrintTitle(std::string title);

int	main(int argc, char *argv[])
{
	Harl		Harl;
	std::string	complain[4] = { "DEBUG", "INFO", "WARNING", "ERROR" };
	int			complainType;

	if (argc != 2)
		return (0);
	complainType = DefineComplainType(complain, argv[1]);
	switch (complainType)
	{
	case 0:
		PrintTitle(complain[0]);
		Harl.complain(complain[0]);
		std::cout << std::endl;
		__attribute__((fallthrough));

	case 1:
		PrintTitle(complain[1]);
		Harl.complain(complain[1]);
		std::cout << std::endl;
		__attribute__((fallthrough));

	case 2:
		PrintTitle(complain[2]);
		Harl.complain(complain[2]);
		std::cout << std::endl;
		__attribute__((fallthrough));

	case 3:
		PrintTitle(complain[3]);
		Harl.complain(complain[3]);
		std::cout << std::endl;
		break;

	default:
		std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
	}
	return (0);
}

int	DefineComplainType(std::string complain[4], std::string userInput)
{
	int	i = 0;

	while (complain[i] != userInput)
		i++;
	return (i);
}

void	PrintTitle(std::string title)
{
	std::cout << "[ " << title << " ]" << std::endl;
}
