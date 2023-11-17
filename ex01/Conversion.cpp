#include "Conversion.hpp"

int	Conversion::ToInt(const std::string string)
{
	int	number = 0;

	_stringStream.str(string);
	_stringStream >> number;
	if (_IsStreamEmpty() == FALSE)
		number = 0;
	_EmptyStream();
	_stringStream.clear();
	return (number);
}

std::string	Conversion::ToString(const int number)
{
	std::string	string;

	_stringStream << number;
	_stringStream >> string;
	_stringStream.clear();
	return (string);
}

int	Conversion::_IsStreamEmpty(void) const
{
	if (_stringStream.eof() == TRUE)
		return (TRUE);
	else
		return (FALSE);
}

void	Conversion::_EmptyStream(void)
{
	_stringStream.str("");
}
