#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

AForm::AForm(void)
	: 	_name(""), _isSigned(false), 
		_signGrade(_lowestGrade), _executeGrade(_lowestGrade)
{
	std::cout << "AForm default constructor is called.\n";
	std::cout << *this << '\n';
}
		
AForm::~AForm(void)
{
	std::cout << "AForm " << _name << " destructor is called.\n";
}

AForm::AForm(const AForm &object)
	:	_name(object.getName()), _isSigned(object.getIsSigned()),
		_signGrade(object.getSignGrade()), _executeGrade(object.getExecuteGrade())
{
	std::cout << "AForm " << _name << " copy constructor is called.\n";
	std::cout << *this << '\n';
}

AForm	&AForm::operator=(const AForm &object)
{
	if (this == &object)
		return (*this);
	std::string	&nameREF = const_cast<std::string &>(this->_name);
	int			&signGradeREF = const_cast<int &>(this->_signGrade);
	int			&executeGradeREF = const_cast<int &>(this->_executeGrade);

	_isSigned = object.getIsSigned();
	nameREF = object.getName();
	signGradeREF = object.getSignGrade();
	executeGradeREF = object.getExecuteGrade();
	return (*this);
}

AForm::AForm(const std::string name)
	: _name(name), _isSigned(false), 
	  _signGrade(_lowestGrade), _executeGrade(_lowestGrade)
{
	std::cout << "AForm " << _name << " constructor is called.\n";
	std::cout << *this << '\n';
}

AForm::AForm(const std::string name, const int signGrade)
	: _name(name), _isSigned(false),
	  _signGrade(_lowestGrade), _executeGrade(_lowestGrade)
{
	std::cout <<"AForm " << _name << " constructor is called.\n";
	_setGrade(const_cast<int &>(this->_signGrade), signGrade);
}

AForm::AForm(const std::string name, const int signGrade, const int executeGrade)
	: _name(name), _isSigned(false),
	  _signGrade(_lowestGrade), _executeGrade(_lowestGrade)
{
	std::cout << "AForm " << _name << " constructor is called.\n";
	_setGrade(const_cast<int &>(this->_signGrade), signGrade);
	_setGrade(const_cast<int &>(this->_executeGrade), executeGrade);
}

AForm::AForm(const int signGrade, const int executeGrade)
	: _name(""), _isSigned(false), 
	  _signGrade(_lowestGrade), _executeGrade(_lowestGrade)
{
	std::cout << "AForm " << _name << " constructor is called.\n";
	_setGrade(const_cast<int &>(this->_signGrade), signGrade);
	_setGrade(const_cast<int &>(this->_executeGrade), executeGrade);
}

std::string	AForm::getName(void) const
{
	return (_name);
}

bool	AForm::getIsSigned(void) const
{
	return (_isSigned);
}

int	AForm::getSignGrade(void) const
{
	return (_signGrade);
}

int	AForm::getExecuteGrade(void) const
{
	return (_executeGrade);
}

void	AForm::_setGrade(int &gradeToSet, const int settingGrade)
{
	try
	{
		std::cout << "AForm: Trying to set grade " << settingGrade << '\n';
		if (settingGrade < _highestGrade)
			throw AForm::GradeTooHighException();
		if (settingGrade > _lowestGrade)
			throw AForm::GradeTooLowException();
		gradeToSet = settingGrade;
		std::cout << "Success to set grade." << '\n';
		std::cout << *this << '\n';
	}
	catch (const AForm::GradeTooHighException &exception)
	{
		std::cerr << "Fail to set grade: " << exception.what() << ".\n";
		gradeToSet = _highestGrade;
		std::cerr << *this << ".\n"; 
	}
	catch (const AForm::GradeTooLowException &exception)
	{
		std::cerr << "Failed to set grade: " << exception.what() << ".\n";
		gradeToSet = _lowestGrade;
		std::cerr << *this << ".\n";
	}
}

void	AForm::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > _signGrade)
		throw AForm::GradeTooLowException();	
	_isSigned = true;	
}

void	AForm::checkExecuteRequirements(const Bureaucrat &executor) const
{
	if (_isSigned == false)
		throw AForm::NotSignedException();
	if (executor.getGrade() > _executeGrade)
		throw AForm::GradeTooLowException();
}

const char	*AForm::GradeTooHighException::what(void) const throw()
{
	return ("Grade is too high");
}

const char	*AForm::GradeTooLowException::what(void) const throw()
{
	return ("Grade is too low");
}

const char	*AForm::NotSignedException::what(void) const throw()
{
	return ("Form is not signed");
}

std::ostream	&operator<<(std::ostream &stream, const AForm &object)
{
	stream << "AForm name: " << object.getName() << ", ";
	if (object.getIsSigned() == true)
		stream << "IsSigned: TRUE, ";
	else
		stream << "IsSigned: FALSE, ";
	stream << "Sign grade: " << object.getSignGrade() << ", ";
	stream << "Execute grade: " << object.getExecuteGrade();
	return (stream);
}