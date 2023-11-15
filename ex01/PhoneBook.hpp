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
		Contact	AddContact(void);
		void	SearchContact(void);
		void	DisplaySavedContact(void);
		int		GetNextIndex(void);
		int		CountNumberOfContact(void);
		int		IsContactExist(void);
		int		IsValidIndex(const std::string string, int *index);

	private:
		Contact		_contact[CONTACT_MAX];
		std::string	_command;
		int			_index;
		int			_numberOfContact;
};

#endif
