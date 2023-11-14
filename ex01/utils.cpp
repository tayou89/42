#include "utils.hpp"

std::string	IntToString(int number)
{
	std::string	string;

	if (number == 0)
		return ("0");
	if (number < 0)
	{
		string = '-';
		number *= (-1);
		return (string + IntToString(number));
	}
	string += (number % 10) + '0';
	if (number / 10 == 0)
		return (string);
	else
		return (IntToString(number / 10) + string);
}
