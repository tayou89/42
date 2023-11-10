#include "PhoneBook.h"

int	main(void)
{
	PhoneBook	phoneBook;
	std::string	command;

	GetCommand(command);
	while (command != "EXIT")
	{
		GetCommand(command);
	}
	return (0);
}
