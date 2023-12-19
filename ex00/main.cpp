#include "Bureaucrat.hpp" 
#include <iostream>

void	testRightCase(void);
void	testWrongCase(void);
void	testIncrementGrade(void);
void	testDecrementGrade(void);

int main(void)
{
	testRightCase();		std::cout << '\n';
	testWrongCase();		std::cout << '\n';
	testIncrementGrade();	std::cout << '\n';
	testDecrementGrade();	std::cout << '\n';
    return (0);
}

void	testRightCase(void)
{
	try
	{
		Bureaucrat	A("A", 1);
		std::cout << A << '\n';
	}
	catch(const std::exception &exception)
	{
		std::cerr << "Error: " << exception.what() << '\n';
	}

	try
	{
		Bureaucrat	B("B", 150);
		std::cout << B << '\n';
	}
	catch(const std::exception &exception)
	{
		std::cerr << "Error: " << exception.what() << '\n';
	}
}


void	testWrongCase(void)
{
	try
	{
		Bureaucrat	A("A", 0);
		std::cout << A << '\n';
	}
	catch(const std::exception &exception)
	{
		std::cerr << "Error: " << exception.what() << '\n';
	}

	try
	{
		Bureaucrat	B("B", 151);
		std::cout << B << '\n';
	}
	catch(const std::exception &exception)
	{
		std::cerr << "Error: " << exception.what() << '\n';
	}
}

void	testIncrementGrade(void)
{
	Bureaucrat	A("A", 1);
	Bureaucrat	B("B", 150);

	try
	{
		A.incrementGrade();
		std::cout << A << '\n';
	}
	catch(const std::exception& exception)
	{
		std::cerr << "Error: " << exception.what() << '\n';
		std::cerr << A << '\n';
	}

	try
	{
		B.incrementGrade();
		std::cout << B << '\n';
	}
	catch(const std::exception& exception)
	{
		std::cerr << "Error: " << exception.what() << '\n';
		std::cerr << B << '\n';
	}
}

void	testDecrementGrade(void)
{	
	Bureaucrat	A("A", 1);
	Bureaucrat	B("B", 150);

	try
	{
		A.decrementGrade();
		std::cout << A << '\n';
	}
	catch(const std::exception& exception)
	{
		std::cerr << "Error: " << exception.what() << '\n';
		std::cerr << A << '\n';
	}

	try
	{
		B.decrementGrade();
		std::cout << B << '\n';
	}
	catch(const std::exception& exception)
	{
		std::cerr << "Error: " << exception.what() << '\n';
		std::cerr << B << '\n';
	}
}