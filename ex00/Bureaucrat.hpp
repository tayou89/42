#ifndef BUREAUCRAT
# define BUREAUCRAT

# include <string>
# include <ostream>
# include <exception>

class   Bureaucrat
{
    public:
        Bureaucrat(void);
        ~Bureaucrat(void);;
        Bureaucrat(const Bureaucrat &object);

		Bureaucrat(const std::string name, const int grade);
        std::string getName(void) const;
        int         getGrade(void) const;
        void        incrementGrade(void);
        void        decrementGrade(void);

        class   GradeTooHighException : public std::exception
        {
            public:
                virtual const char  *what(void) const throw();
        };
        class   GradeTooLowException : public std::exception
        {
            public:
                virtual const char  *what(void) const throw();
        };

    private:
        Bureaucrat   &operator=(const Bureaucrat &object);

        static const int	_highestGrade = 1;
		static const int	_lowestGrade = 150;
        const std::string   _name;
        int                 _grade;
};

std::ostream &operator<<(std::ostream &stream, const Bureaucrat &object);

#endif