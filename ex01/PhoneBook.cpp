#include "PhoneBook.hpp"
#include <iomanip>

static void	PrintColumnText(const std::string text[COLUMN_COUNT]);

PhoneBook::PhoneBook(void) 
	: _command(""), _contactIndex(0), _contactCount(0)
{
}

std::string	PhoneBook::GetCommand(void)
{
	_command = _input.Get("Command: ");
	return (_command);
}

void	PhoneBook::ExecuteCommand(void)
{
	if (_command == "ADD")
		_AddContact();
	if (_command == "SEARCH")
		_SearchContact();
	_command = "";
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
	if (_contactCount < CONTACT_MAX)
		_contactCount++;
}

void	PhoneBook::_SearchContact(void)
{
	std::string			indexString;
	int					indexToSearch = 0;

	_DisplaySavedContact();
	if (_IsPhoneBookEmpty() == TRUE)
	{
		std::cout << "No Contact to search." << std::endl;
		return ;
	}
	indexString = _input.Get("Index to search: ");
	indexToSearch = _conversion.ToInt(indexString);
	if (_IsValidIndex(indexToSearch) == TRUE)
		_contact[indexToSearch - 1].PrintFieldInfo();
	else
		std::cout << "Error: Invalid Index." << std::endl;
}

void	PhoneBook::_DisplaySavedContact(void)
{
	std::string	text[COLUMN_COUNT] = {"Index", "First Name", "Last Name", "Nick Name"};
	int			contactIndex;
	int			i;

	PrintColumnText(text);
	for (contactIndex = 0; contactIndex < _contactCount; contactIndex++)
	{
		text[0] = _conversion.ToString(contactIndex + 1);
		for (i = 1; i < COLUMN_COUNT; i++)
			text[i] = _contact[contactIndex].GetField(i - 1);
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

int	PhoneBook::_IsPhoneBookEmpty(void) const
{
	if (_contactCount == 0)
		return (TRUE);
	else
		return (FALSE);
}

int	PhoneBook::_IsValidIndex(int index) const
{
	if (index >= 1 && index <= _contactCount)
		return (TRUE);
	else
		return (FALSE);
}
