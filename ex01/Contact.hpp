#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include "Input.hpp"

# define FIELD_COUNT	5

typedef enum FieldType 
{
	FIRST_NAME, 
	LAST_NAME, 
	NICK_NAME, 
	PHONE_NUMBER, 
	DARKEST_SECRET
}	FieldType;

class	Contact
{
	private:
		std::string	_field[FIELD_COUNT];
		Input		_input;

	public:
		void		GetFieldInfo(void);
		void		PrintFieldInfo(void) const;
		std::string	GetField(int fieldType) const;
};

#endif
