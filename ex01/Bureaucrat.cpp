#include "Bureaucrat.hpp"
#include <iostream>

Bureaucrat::Bureaucrat(void)
    : _name(""), _grade(_lowestGrade)
{
    std::cout << "Bureaucrat default constructor is called.\n";
	std::cout << *this << std::endl;
}

Bureaucrat::~Bureaucrat(void)
{
    std::cout << "Bureaucrat " << _name << " destructor is called.\n";
}

Bureaucrat::Bureaucrat(const Bureaucrat &object)
    : _name(object.getName()), _grade(object.getGrade())
{
    std::cout << "Bureaucrat " << _name << " copy constructor is called.\n";
	std::cout << *this << std::endl;
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
    std::cout << "Bureaucrat constructor is called." << std::endl;
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
	std::cout << *this << std::endl;
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
	std::cout << *this << std::endl;
    _setGrade(_grade - 1);
}

void    Bureaucrat::decrementGrade(void)
{
	std::cout << *this << std::endl;
    _setGrade(_grade + 1);
}

void    Bureaucrat::_setGrade(const int grade)
{
    try
    {
		std::cout << "Trying to set grade " << grade << std::endl;
        if (grade < _highestGrade)
            throw Bureaucrat::GradeTooHighException();
        if (grade > _lowestGrade)
            throw Bureaucrat::GradeTooLowException();
        this->_grade = grade;
        std::cout << "Sucess to set grade." << std::endl;
		std::cout << *this << std::endl;
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
    stream << object.getName() << ", bureaucrat grade " << object.getGrade() << ".";
	return (stream);
}