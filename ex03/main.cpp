#include <iostream>
#include "Intern.hpp"

int	main(void)
{
	Intern		intern;
	AForm		*formPTR = NULL;
	std::string	formTarget("Home");

	formPTR = intern.makeForm("Shrubbery Creation", formTarget);	
	delete formPTR;
	std::cout << '\n';

	formPTR = intern.makeForm("Robotomy Request", formTarget);
	delete formPTR;
	std::cout << '\n';
	
	formPTR = intern.makeForm("Presidential Pardon", formTarget);
	delete formPTR;
	std::cout << '\n';
	
	formPTR = intern.makeForm("abc", formTarget);
	delete formPTR;
	std::cout << '\n';
	return (0);
}