#include "utils.hpp"
#include <cctype>
#include <cstdio>
#include <climits>

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

int	StringToInteger(const std::string string, int *number)
{
	int	beforeNumber = 0;
	int	afterNumber;
	int	sign = 1;
	int	i = 0;

	if (string[i] == '-' || string[i] == '+')
	{
		i++;
		if (string[i] == '-')
			sign *= (-1);
	}
	while (string[i] != '\0')
	{
		if (isdigit(string[i]) == FALSE)
			return (FALSE);
		afterNumber = beforeNumber * 10 + (string[i] - '0');
		if (afterNumber / 10 != beforeNumber)
			return (FALSE);
		beforeNumber = afterNumber;
		i++;
	}
	afterNumber *= sign;
	*number = afterNumber;
	return (TRUE);
}

int	IsValidInput(void)
{
	if (std::cin.eof() == TRUE)
	{
		while (std::cin.eof() == TRUE)
		{
			clearerr(stdin);
			std::cin.clear();
			std::cin.ignore(LLONG_MAX, '\n');
		}
		return (FALSE);
	}
	else if (std::cin.fail() == TRUE)
	{
		while (std::cin.fail() == TRUE)
		{
			std::cin.clear();
			std::cin.ignore(LLONG_MAX, '\n');
		}
		return (FALSE);
	}
	else
		return (TRUE);
}
