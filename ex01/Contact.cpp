#include "phonebook.hpp"

Contact::Contact(void)
{
	for (int i = 0; i < FIELD_MAX; i++)
		field[i] = NULL;
}

void	Contact::get_field_data(std::string data, int field_typ)
{
	field[field_type] = data;
}
