#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>
# include "Contact.hpp"
# include "Input.hpp"
# include "Conversion.hpp"

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

	private:
		void		_AddContact(void);
		void		_SearchContact(void);
		void		_DisplaySavedContact(void);
		void		_ResetContactIndex(void);
		void		_CountContact(void);
		int			_IsPhoneBookEmpty(void) const;
		int			_IsValidIndex(int index) const;

		Contact		_contact[CONTACT_MAX];
		Input		_input;
		Conversion	_conversion;
		std::string	_command;
		int			_contactIndex;
		int			_contactCount;
};

#endif
