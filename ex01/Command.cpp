#include "command.hpp"
#include "utils.hpp"

void	GetCommand(std::string &command)
{
	std::cout << "Command(ADD, SEARCH, EXIT): ";
	std::getline(std::cin, command);
}

void	ExecuteCommand(const std::string command, PhoneBook &phoneBook)
{
	if (IsValidInput() == FALSE)
		return ;
	else if (command == "ADD")
		phoneBook.AddContact();
	else if (command == "SEARCH")
		phoneBook.SearchContact();
	else
		return ;
}