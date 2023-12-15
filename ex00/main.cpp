#include "Bureaucrat.hpp" 
#include <iostream>

int main(void)
{
	Bureaucrat	A("A");			std::cout << std::endl;
	Bureaucrat	B("B", 1);		std::cout << std::endl;
	Bureaucrat	C("C", 0);		std::cout << std::endl;
	Bureaucrat	D("D", 151);	std::cout << std::endl;
	Bureaucrat	E("E", 3);		std::cout << std::endl;
	Bureaucrat	G("G", 148);	std::cout << std::endl;

	A.decrementGrade();			std::cout << std::endl;
	B.incrementGrade();			std::cout << std::endl;

	E.incrementGrade();			std::cout << std::endl;
	E.incrementGrade();			std::cout << std::endl;
	E.incrementGrade();			std::cout << std::endl;

	G.decrementGrade();			std::cout << std::endl;
	G.decrementGrade();			std::cout << std::endl;
	G.decrementGrade();			std::cout << std::endl;
    return (0);
}