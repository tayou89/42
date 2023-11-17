#include "Contact.hpp"

void	Contact::GetFieldInfo(void)
{
	const char	*prompt[FIELD_COUNT] = 
	{"First name: ", "Last name: ", "Nick name: ", "Phone number: ", "Darkest secret: "};
	int			i = 0;

	while (i < FIELD_COUNT)
	{
		_field[i] = _input.Get(prompt[i]);
		if (_field[i] != "")
			i++;
	}
}

void	Contact::PrintFieldInfo(void) const
{
	const char	*prompt[FIELD_COUNT] = 
	{"First name: ", "Last name: ", "Nick name: ", "Phone number: ", "Darkest secret: "};
	int			i;

	for (i = 0; i < FIELD_COUNT; i++)
	{
		std::cout << prompt[i];
		std::cout << _field[i];
		std::cout << std::endl;
	}
}

std::string	Contact::GetField(int fieldType) const
{
	return (_field[fieldType]);
}
