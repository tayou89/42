#include "Command.hpp"

void	GetCommand(std::string &command)
{
	std::cout << "Command(ADD, SEARCH, EXIT): ";
	std::cin >> command;
}

void	ExecuteCommand(const std::string command, PhoneBook &phoneBook)
{
	if (command == "ADD")
		phoneBook.AddContact();
	else if (command == "SEARCH")
		phoneBook.SearchContact();
	else
		return ;
}
