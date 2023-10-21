#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <string>
# include <iostream>

# define FIRST_NAME		0
# define LAST_NAME		1
# define NICK_NAME		2
# define PHONE_NUMBER	3
# define DARKEST_SECRET	4

# define FIELD_MAX		5

class	Contact
{
	private:
		std::string	field[FIELD_MAX];
	public:
		Contact(void);
		void	get_field_data(std::string data, int field_type);

};

#endif
