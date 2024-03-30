#include <iostream>
#include "Intern.hpp"

int	main(void)
{
	Intern		intern;
	AForm		*formPTR = NULL;
	std::string	formTarget("Home");

	formPTR = intern.makeForm("Shrubbery Creation", formTarget);	
	std::cout << '\n'; delete formPTR;	std::cout << '\n';

	formPTR = intern.makeForm("Robotomy Request", formTarget);
	std::cout << '\n'; delete formPTR; std::cout << '\n';
	
	formPTR = intern.makeForm("Presidential Pardon", formTarget);
	std::cout << '\n'; delete formPTR; std::cout << '\n';
	
	formPTR = intern.makeForm("abc", formTarget);
	std::cout << '\n'; delete formPTR; std::cout << '\n';
	return (0);
}