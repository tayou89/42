#include "phonebook.hpp"

PhoneBook::PhoneBook(void) : index(0) { }

int	PhoneBook::get_current_index(void)
{
	return (index);
}

void	PhoneBook::renew_index(void)
{
	index++;
	if (index > INDEX_MAX)
		index = 0;
}
