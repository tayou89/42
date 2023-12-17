#include "Bureaucrat.hpp" 
#include "Form.hpp"
#include <iostream>

void	formConstructorTest(void);
void	bureaucratSignTest(void);

int main(void)
{
	formConstructorTest();
	bureaucratSignTest();
    return (0);
}

void	formConstructorTest(void)
{
	Form	formA;				std::cout << '\n';
	Form	formB("B");			std::cout << '\n';
	Form	formC("C", 0);		std::cout << '\n';
	Form	formD("D", 1, 151);	std::cout << '\n';
}

void	bureaucratSignTest(void)
{
	Bureaucrat	bureaucratA("A", 50);	std::cout << '\n';
	Form 		formA("A", 2);			std::cout << '\n';
	Form 		formB("B", 51);			std::cout << '\n';

	bureaucratA.signForm(formA);		std::cout << '\n';
	bureaucratA.signForm(formB);		std::cout << '\n';
}