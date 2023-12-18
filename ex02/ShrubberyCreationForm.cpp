#include "ShrubberyCreationForm.hpp"
#include <iostream>
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(void)
	: AForm(145, 137), _target("") 
{
	std::cout << "ShrubberyCreationForm default constructor is called, "
	          << "having a target " << _target << ".\n";
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
	std::cout << "ShrubberyCreationForm having a target " << _target
	          << " destructor is called.\n";
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &object)
	: AForm(object.getName(), object.getSignGrade(), object.getExecuteGrade()),
	  _target(object.getTarget())
{
	std::cout << "ShrubberyCreationForm copy constructor is called, "
			  << "having a target " << _target << ".\n";
}

ShrubberyCreationForm	&ShrubberyCreationForm::operator=(const ShrubberyCreationForm &object)
{
	if (this == &object)
		return (*this);
	AForm::operator=(object); 
	_target = object.getTarget();
	return (*this);
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string target)
	: AForm(145, 137), _target(target)
{
	std::cout << "ShrubberyCreationForm constructor is called, "
	          << "having a target " << _target << ".\n";
}

void	ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	if (getIsSigned() == false)
		throw ("form is not signed");
	if (executor.getGrade() > getExecuteGrade())
		throw AForm::GradeTooLowException();
	_writeASCIITree();
}

void	ShrubberyCreationForm::_writeASCIITree(void) const
{
	std::ofstream	fileStream;
	std::string		fileName = _target + "_shrubbery";
	std::string		asciiTree = "\n\
	      ,    ,    *   ,  ,   , \n\
	   ,    ,      ***    ,  ,   \n\
	      *	  ,   *****     *    \n\
	  , ,*** ,   ******* , ***  ,\n\
	 ,  *****   ********* *****  \n\
	      | ,      ||| ,    |    \n\
    ^^^___^^_^____^_^_^_^___^_^_^\n ";

	fileStream.open(fileName.c_str());
	if (fileStream.is_open() == false)
		std::cerr << "Error: opening file failed: " << fileName << '\n';
	fileStream << asciiTree;
	fileStream.close();
}

std::string	ShrubberyCreationForm::getTarget(void) const
{
	return (_target);
}