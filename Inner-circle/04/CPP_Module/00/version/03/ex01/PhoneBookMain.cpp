#include "PhoneBook.hpp"
#include "Command.hpp"

int	main(void)
{
	PhoneBook	phoneBook;
	std::string	command;

	GetCommand(command);
	while (command != "EXIT")
	{
		ExecuteCommand(command, phoneBook);
		GetCommand(command);
	}
	return (0);
}
