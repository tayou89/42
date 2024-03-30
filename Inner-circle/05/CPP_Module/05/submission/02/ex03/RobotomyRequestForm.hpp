#ifndef ROBO_TO_MY_REQUEST_FORM_HPP
# define ROBO_TO_MY_REQUEST_FORM_HPP

# include <string>
# include "AForm.hpp"
# include "Bureaucrat.hpp"

class	RobotomyRequestForm : public AForm
{
	public:
		RobotomyRequestForm(void);
		virtual ~RobotomyRequestForm(void);
		RobotomyRequestForm(const RobotomyRequestForm &object);

		RobotomyRequestForm(const std::string target);
		virtual void	execute(Bureaucrat const &executor) const;
		std::string		getTarget(void) const;

	private:
		RobotomyRequestForm	&operator=(const RobotomyRequestForm &object);

		static const int	_signGrade = 72;
		static const int	_executeGrade = 45;
		std::string			_target;
};

#endif