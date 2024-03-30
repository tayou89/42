#include "PhoneBook.hpp"

static void	ShowTitle(void);
static void	PrintAtCenter(const std::string string, int width);

PhoneBook::PhoneBook(void) : index(0), numberOfContact(0) {}

Contact	PhoneBook::AddContact(void)
{
	GetNextIndex();
	contact[index].GetFieldInfo();
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
	if (IsContactExist == FALSE)
		return ;
	std::cout << "Index to search: ";
	std::cin >> indexToSearch;
	while (IsValidContact(indexToSearch) == FALSE)
	{
		std::cout << "Error: Invalid Index.\n";
		if (std::cin.fail() == TRUE)
		{
			std::cin.clear();
			std::cin.ignore(100, '\n');
		}
		std::cout << "Index to search: ";
		std::cin >> indexToSearch;
	}
	contact[indexToSearch - 1].DisplayContactInfo();
}

void	PhoneBook::DisplaySavedContact(void)
{
	int			contactIndex;
	int			i;

	ShowTitle();
	for (contactIndex = 1; contactIndex <= numberOfContact; contactIndex++)
	{
		std::cout << COLUMN_SEPERATOR;
		PrintAtCenter(std::to_string(contactIndex), COLUMN_WIDTH);
		std::cout << COLUMN_SEPERATOR;
		for (i = 0; i < COLUMN_COUNT - 1; i++)
		{
			PrintAtCenter(contact[contactIndex].ReturnField(i), COLUMN_WIDTH);
			std::cout << COLUMN_SEPERATOR;
		}
		std::cout << std::endl;
	}
}


static void	ShowTitle(void)
{
	std::string	title[COLUMN_COUNT] = {"Index", "First Name", "Last Name", "Nick Name"};
	int			i;

	std::cout << COLUMN_SEPERATOR;
	for (i = 0; i < COLUMN_COUNT; i ++)
	{
		PrintAtCenter(title[i], COLUMN_WIDTH);
		std::cout << COLUMN_SEPERATOR;
	}
	std::cout << std::endl;
}

static void	PrintAtCenter(const std::string string, int width)
{
	int	leftSpace = (width - string.length()) / 2;
	int	rightSpace = width - leftSpace - string.length();
	int	i;

	for (i = 0; i < leftSpace; i++)
		std::cout << ' ';
	if (string.length() > (unsigned long) width)
		std::cout << string.substr(0, width - 1) << ".";
	else
		std::cout << string;
	for (i = 0; i < rightSpace; i++)
		std::cout << ' ';
}

int	PhoneBook::IsContactExist(void)
{
	if (numberOfContact == 0)
	{
		std::cout << "No contact to search";
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
		return (FALSE);
}
