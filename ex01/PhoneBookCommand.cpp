#include "PhoneBook.hpp"
#include <iostream>
#include <cstring>

std::string	GetCommand(std::string &command)
{
	std::cout << "Command(ADD, SEARCH, EXIT): ";
	std::cin >> command;
}
