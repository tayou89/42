#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "contact.hpp"

# define INDEX_MAX	8

class	PhoneBook
{
	private:
		Contact	contact[INDEX_MAX];
		int		index;
	public:
		Phonebook(void);
		int		get_current_index(void);
		void	renew_index(void);
};

#ifndef
