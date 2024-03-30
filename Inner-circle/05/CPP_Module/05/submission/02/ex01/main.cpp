#include "Bureaucrat.hpp" 
#include "Form.hpp"
#include <iostream>

void	correctFormTest(void);
void	wrongFormTest(void);
void	signFormTest(void);

int main(void)
{
	correctFormTest();	std::cout << '\n';
	wrongFormTest();	std::cout << '\n';
	signFormTest();		std::cout << '\n';
    return (0);
}

void	correctFormTest(void)
{
	try
	{
		Form	A("A", 1, 150); 
		std::cout << A << '\n';
	}
	catch(const std::exception& e)
	{
		std::cerr << "Error: "<< e.what() << '\n';
	}
}

void	wrongFormTest(void)
{
	try
	{
		Form	A("A", 0, 150); 
		std::cout << A << '\n';
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		Form	A("A", 1, 151); 
		std::cout << A << '\n';
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

void	signFormTest(void)
{
	Form		A("A", 50, 50);
	Bureaucrat	B("B", 20);
	Bureaucrat	C("C", 70);
	
	B.signForm(A);
	C.signForm(A);
}