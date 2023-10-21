#include "phonebook.hpp"

int	main(void)
{
	PhoneBook	phonebook();
	std::string	command;

	command = get_command();
	while (command != "EXIT")
	{
		execute_command(command, phonebook);
		get_command();
	}
	return (0);
}
