#include "Contact.hpp"

Contact	Contact::GetFieldInfo(void)
{
	const char	*prompt[FIELD_COUNT] = 
	{"First name: ", "Last name: ", "Nick name: ", "Phone number: ", "Darkest secret: "};
	int			i;

	for (i = 0; i < FIELD_COUNT; i++)
	{
		std::cout << prompt[i];
		std::cin >> field[i];
	}
	return (*this);
}

std::string	Contact::ReturnField(int fieldType)
{
	return (field[fieldType]);
}

Contact	Contact::DisplayContactInfo(void)
{
	const char	*prompt[FIELD_COUNT] = 
	{"First name: ", "Last name: ", "Nick name: ", "Phone number: ", "Darkest secret: "};
	int			i;

	for (i = 0; i < FIELD_COUNT; i++)
	{
		std::cout << prompt[i];
		std::cout << field[i];
		std::cout << std::endl;
	}
	return (*this);
}
