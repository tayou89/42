#include "Input.hpp"

Input::Input(void)
	: input("")
{
}

std::string Input::Get(const char *prompt)
{
	if (prompt != NULL)
		std::cout << prompt;
	std::getline(cin, _input);
	if (std::cin.eof() == TRUE)
		_HandleEOF();
	return (_input);
}

void	Input::_HandleEOF(void) const
{
	while (std::cin.eof() == TRUE)
	{
		clearerr(stdin);
		std::cin.clear();
	}
}
