#include "phonebook.hpp"

std::string	get_command(void)
{
	std::string	command;

	std::cout << "Command(ADD, SEARCH, EXIT): ";
	std::cin >> command;
	return (command);
}

void	execute_command(std::string command, PhoneBook &phonebook)
{
	if (command == "ADD")
		execute_add(phonebook);
	else if (command == "SEARCH")
		execute_search(phonebook);
	else
		return ;
}

void	execute_add(PhoneBook &phonebook)
{
	std::string	prompt[5];
	std::string	data;
	int			index;

	define_prompt(prompt);
	index = phonebook.get_current_index();
	for (int i = 0; i < FIELD_MAX; i++)
	{
		std::cout << prompt[i];
		std::cin >> data
		phonebook.contact[index].get_field_data(data, i);
	}
	phonebook.renew_index();
}

void	define_prompt(std::string *prompt)
{
	prompt[FIRST_NAME] = "First name: ";
	prompt[LAST_NAME] = "Last name: ";
	prompt[NICK_NAME] = "Nick name: ";
	prompt[PHONE_NUMBER] = "Phone number: ";
	Prompt[DARKEST_SECRET] = "Darkest secret: ";
}
