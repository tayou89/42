#include "PhoneBook.hpp"
#include "utils.hpp"
#include <iomanip>

static void	PrintColumnText(const std::string text[COLUMN_COUNT]);

PhoneBook::PhoneBook(void) : 
	_contactIndex(0), _contactCount(0), _command("")
{
}

std::string	PhoneBook::GetCommand(void)
{
	input.get("Command: ");
}

void	PhoneBook::ExecuteCommand(void)
{
	if (_command == "ADD")
		_AddContact();
	else if (_command == "SEARCH")
		_SearchContact();
	else
		return ;
}

void	PhoneBook::_AddContact(void)
{
	_contact[_contactIndex].GetFieldInfo();
	_ResetContactIndex();
	_CountContact();
}

void	PhoneBook::_ResetContactIndex(void)
{
	if (_contactIndex == CONTACT_MAX - 1)
		_contactIndex = 0;
	else
		_contactIndex += 1;
}

void	PhoneBook::_CountContact(void)
{
	if (contactCount < CONTACT_MAX)
		contactCount++;
}

void	PhoneBook::_SearchContact(void) const
{
	std::string			string;
	std::stringstream	stringstream;
	const char			*errorMessage = "Error: Invalid Index.";
	int					indexToSearch = 0;

	_DisplaySavedContact();
	if (IsContactExist() == FALSE)
		return ;
	std::cout << "Index to search: ";
	std::getline(std::cin, string);
	stringstream.str(string);
	stringstream >> indexToSearch;
	if (std::cin.eof() == TRUE)
		HandleEOF(errorMessage);
	if (IsValidInput() == TRUE && IsValidIndex(string, &indexToSearch) == TRUE
		&& string != "")
		contact[indexToSearch - 1].DisplayContactInfo();
	else
		std::cout << "Error: Invalid Index." << std::endl;
}

void	PhoneBook::_DisplaySavedContact(void) const
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

void	PhoneBook::_HandleEOF(const char *message)
{
	while (std::cin.eof() == TRUE)
	{
		clearerr(stdin);
		std::cin.clear();
	}
	if (message != NULL)
		std::cout << message << std::endl;
}
