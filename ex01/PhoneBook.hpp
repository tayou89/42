#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"

# define TRUE				1
# define FALSE				0

# define CONTACT_MAX		8
# define COLUMN_COUNT		4
# define COLUMN_WIDTH		10
# define COLUMN_SEPERATOR	"|"

class	PhoneBook
{
	private:
		Contact	contact[CONTACT_MAX];
		int		index;
		int		numberOfContact;
	public:
		PhoneBook(void);
		Contact	AddContact(void);
		void	SearchContact(void);
		void	DisplaySavedContact(void);
		int		GetNextIndex(void);
		int		CountNumberOfContact(void);
		int		IsValidContact(int index);
};

#endif
