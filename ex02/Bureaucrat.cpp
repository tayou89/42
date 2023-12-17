#include "Bureaucrat.hpp"
#include <iostream>

Bureaucrat::Bureaucrat(void)
    : _name(""), _grade(_lowestGrade)
{
    std::cout << "Bureaucrat default constructor is called.\n";
	std::cout << *this << '\n';
}

Bureaucrat::~Bureaucrat(void)
{
    std::cout << "Bureaucrat " << _name << " destructor is called.\n";
}

Bureaucrat::Bureaucrat(const Bureaucrat &object)
    : _name(object.getName()), _grade(object.getGrade())
{
    std::cout << "Bureaucrat " << _name << " copy constructor is called.\n";
	std::cout << *this << '\n';
}

Bureaucrat  &Bureaucrat::operator=(const Bureaucrat &object)
{
    std::string &nameREF = const_cast<std::string &>(this->_name);

    if (this != &object)
    {
        nameREF = object.getName();
        this->_grade = object.getGrade();
    }
    return (*this);
}

Bureaucrat::Bureaucrat(const int grade)
    : _name("")
{
    std::cout << "Bureaucrat constructor is called." << '\n';
    _setGrade(grade);
}

Bureaucrat::Bureaucrat(const std::string name, const int grade)
    : _name(name)
{
    std::cout << "Bureaucrat " << _name << " constructor is called.\n";
    _setGrade(grade);
}

Bureaucrat::Bureaucrat(const std::string name)
    : _name(name), _grade(_lowestGrade)
{
	std::cout << "Bureaucrat " << _name << " constructor is called.\n";
	std::cout << *this << '\n';
}

std::string Bureaucrat::getName(void) const
{
    return (_name);    
}

int Bureaucrat::getGrade(void) const
{
    return (_grade);
}

void    Bureaucrat::incrementGrade(void)
{
	std::cout << *this << '\n';
    _setGrade(_grade - 1);
}

void    Bureaucrat::decrementGrade(void)
{
	std::cout << *this << '\n';
    _setGrade(_grade + 1);
}

void    Bureaucrat::_setGrade(const int grade)
{
    try
    {
		std::cout << "Bureaucat: Trying to set grade " << grade << '\n';
        if (grade < _highestGrade)
            throw Bureaucrat::GradeTooHighException();
        if (grade > _lowestGrade)
            throw Bureaucrat::GradeTooLowException();
        this->_grade = grade;
        std::cout << "Sucess to set grade.\n";
		std::cout << *this << '\n';
    }
    catch (const Bureaucrat::GradeTooHighException &exception)
    {
        std::cerr << "Failed to set grade: " << exception.what() << ".\n";
        _grade = _highestGrade;
        std::cerr << *this << '\n'; 
    }
    catch (const Bureaucrat::GradeTooLowException &exception)
    {
        std::cerr << "Failed to set grade: " << exception.what() << ".\n";
        _grade = _lowestGrade;
        std::cout << *this << '\n';
    } 
}

void	Bureaucrat::signForm(AForm &form)
{
	try
	{
		form.beSigned(*this);	
		std::cout << *this << " signed " << form << ".\n";
	}
	catch(const std::exception &exception)
	{
		std::cerr << *this << " couldn't sign " << form
				<< " becuase " << exception.what() << ".\n";
	}
}

void	Bureaucrat::executeForm(AForm const &form)
{
	try
	{
		form.execute(*this);
		std::cout << *this << " execute " << form << ".\n";
	}
	catch (const std::exception& exception)
	{
		std::cerr << *this << " couldn't execute " << form
		          << " because " << exception.what() << ".\n"; 
	}
	catch (const std::string &reason)
	{
		std::cerr << *this << " couldn't execute " << form 
		          << " because " << reason << ".\n";
	}
}

const char  *Bureaucrat::GradeTooHighException::what(void) const throw()
{
    return ("Grade is too high");
}

const char  *Bureaucrat::GradeTooLowException::what(void) const throw()
{
    return ("Grade is too low");
}

std::ostream    &operator<<(std::ostream &stream, const Bureaucrat &object)
{
    stream << object.getName() << ", bureaucrat grade " << object.getGrade();
	return (stream);
}