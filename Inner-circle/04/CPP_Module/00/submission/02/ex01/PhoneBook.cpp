#include "PhoneBook.hpp"
#include "utils.hpp"
#include <iomanip>

static void	PrintColumnText(const std::string text[COLUMN_COUNT]);

PhoneBook::PhoneBook(void) : index(0), numberOfContact(0) {}

Contact	PhoneBook::AddContact(void)
{
	contact[index].GetFieldInfo();
	GetNextIndex();
	CountNumberOfContact();
	return (contact[index]);
}

int	PhoneBook::GetNextIndex(void)
{
	if (index == CONTACT_MAX - 1)
		index = 0;
	else
		index += 1;
	return (index);
}

int	PhoneBook::CountNumberOfContact(void)
{
	if (numberOfContact < CONTACT_MAX)
		numberOfContact++;
	return (numberOfContact);
}

void	PhoneBook::SearchContact(void)
{
	std::string	string;
	int			indexToSearch = 0;

	DisplaySavedContact();
	if (IsContactExist() == FALSE)
		return ;
	std::cout << "Index to search: ";
	std::getline(std::cin, string);
	if (IsValidInput() == TRUE && IsValidIndex(string, &indexToSearch) == TRUE
		&& string != "")
		contact[indexToSearch - 1].DisplayContactInfo();
	else
		std::cout << "Error: Invalid Index." << std::endl;
}

void	PhoneBook::DisplaySavedContact(void)
{
	std::string	text[COLUMN_COUNT] = {"Index", "First Name", "Last Name", "Nick Name"};
	int			contactIndex;
	int			i;

	PrintColumnText(text);
	for (contactIndex = 0; contactIndex < numberOfContact; contactIndex++)
	{
		text[0] = IntToString(contactIndex + 1);
		for (i = 1; i < COLUMN_COUNT; i++)
			text[i] = contact[contactIndex].ReturnField(i - 1);
		PrintColumnText(text);
	}
}

static void	PrintColumnText(const std::string text[COLUMN_COUNT])
{
	int	i;

	std::cout << COLUMN_SEPERATOR;
	for (i = 0; i < COLUMN_COUNT; i++)
	{
		if (text[i].length() > COLUMN_WIDTH)
			std::cout << text[i].substr(0, COLUMN_WIDTH - 1) << ".";
		else
			std::cout << std::setw(COLUMN_WIDTH) << text[i];
		std::cout << COLUMN_SEPERATOR;
	}
	std::cout << std::endl;
}

int	PhoneBook::IsContactExist(void)
{
	if (numberOfContact == 0)
	{
		std::cout << "No contact to search.\n";
		return (FALSE);
	}
	else
		return (TRUE);
}

int	PhoneBook::IsValidIndex(const std::string string, int *index)
{
	if (StringToInteger(string, index) == FALSE)
		return (FALSE);
	else if (*index < 1 || *index > numberOfContact)
		return (FALSE);
	else
		return (TRUE);
}
