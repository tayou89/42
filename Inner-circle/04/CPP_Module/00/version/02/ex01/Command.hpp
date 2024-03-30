#ifndef COMMAND_HPP
# define COMMAND_HPP

#include "PhoneBook.hpp"

#include <iostream>

void	GetCommand(std::string &command);
void	ExecuteCommand(const std::string command, PhoneBook &phoneBook);

#endif
