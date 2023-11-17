#include "PhoneBook.hpp"

int	main(void)
{
	PhoneBook	phoneBook;

	while (phoneBook.GetCommand() != "EXIT")
		phoneBook.ExecuteCommand();
	return (0);
}
