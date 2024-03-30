#include "Input.hpp"
#include <cstdio>
#include <climits>

std::string Input::Get(const char *prompt)
{
	std::string	input = "";

	if (prompt != NULL)
		std::cout << prompt;
	std::getline(std::cin, input);
	if (std::cin.eof() == TRUE)
		_HandleEOF();
	_EmptyStream();
	return (input);
}

void	Input::_HandleEOF(void) const
{
	while (std::cin.eof() == TRUE)
	{
		clearerr(stdin);
		std::cin.clear();
		std::cin.ignore();
	}
}

void	Input::_EmptyStream(void)
{
	fflush(stdin);
}
