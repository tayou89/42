#include "ShrubberyCreationForm.hpp"
#include <iostream>
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(void)
	: AForm("Shrubbery Creation", _signGrade, _executeGrade), _target("") 
{
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &object)
	: AForm(object.getName(), object.getSignGrade(), object.getExecuteGrade()),
	  _target(object.getTarget())
{
}

ShrubberyCreationForm	&ShrubberyCreationForm::operator=(const ShrubberyCreationForm &object)
{
	if (this == &object)
		return (*this);
	_target = object.getTarget();
	return (*this);
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string target)
	: AForm("Shrubbery Creation", _signGrade, _executeGrade), _target(target)
{
}

void	ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{	
	checkExecuteRequirements(executor);
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