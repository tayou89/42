#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"
# include <iostream>

# define TRUE				1
# define FALSE				0

# define CONTACT_MAX		8
# define COLUMN_COUNT		4
# define COLUMN_WIDTH		10
# define COLUMN_SEPERATOR	"|"

class	PhoneBook
{
	public:
		PhoneBook(void);
		std::string	GetCommand(void);
		void		ExecuteCommand(void);

		Input		input;

	private:
		void		_AddContact(void);
		void		_SearchContact(void) const;
		void		_DisplaySavedContact(void) const;
		void		_ResetContactIndex(void);
		void		_CountContact(void);
		int			_IsContactExist(void);
		int			_IsValidIndex(const std::string string, int *index);
		void		_HandleEOF(const char *message);

		Contact		_contact[CONTACT_MAX];
		std::string	_command;
		int			_contactIndex;
		int			_contactCount;
};

#endif
