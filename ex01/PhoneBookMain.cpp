#include "PhoneBook.hpp"
#include "command.hpp"

int	main(void)
{
	PhoneBook	phoneBook;

	phoneBook.setCommand();
	while (command != "EXIT")
	{
		ExecuteCommand(command, phoneBook);
		GetCommand(command);
	}
	return (0);
}