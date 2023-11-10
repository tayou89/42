#include "PhoneBook.hpp"

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
	int	indexToSearch;

	DisplaySavedContact();
	if (IsContactExist() == FALSE)
		return ;
	std::cout << "Index to search: ";
	std::cin >> indexToSearch;
	if (IsValidIndex(indexToSearch) == FALSE)
		return ;
	else
		contact[indexToSearch - 1].DisplayContactInfo();
}

void	PhoneBook::DisplaySavedContact(void)
{
	std::string	text[COLUMN_COUNT] = {"Index", "First Name", "Last Name", "Nick Name"};
	int			contactIndex;
	int			i;

	PrintColumnText(text);
	for (contactIndex = 0; contactIndex < numberOfContact; contactIndex++)
	{
		text[0] = std::to_string(contactIndex + 1);
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
		std::cout.width(COLUMN_WIDTH);
		std::cout << std::left << text[i];
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

int	PhoneBook::IsValidIndex(int index)
{
	if (index >= 1 && index <= numberOfContact)
		return (TRUE);
	else
	{
		if (std::cin.fail() == TRUE)
		{
			std::cin.clear();
			std::cin.ignore(100, '\n');
		}
		std::cout << "Error: Invalid Index.\n";
		return (FALSE);
	}
}
