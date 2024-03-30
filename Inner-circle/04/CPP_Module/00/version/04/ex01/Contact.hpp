#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>

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
		std::string	field[FIELD_COUNT];
	public:
		Contact		GetFieldInfo(void);
		Contact		DisplayContactInfo(void);
		std::string	ReturnField(int fieldType);	
};

#endif
