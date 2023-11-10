#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# define CONTACT_MAX	8

class	PhoneBook
{
	private:
		Contact	contact[CONTACT_MAX];
	public:
		AddContact(PhoneBook &phoneBook);
		SearchContact(const PhoneBook &phoneBook);
};

#endif
