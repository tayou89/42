#ifndef BUREAUCRAT
# define BUREAUCRAT

# include <ostream>

class   Bureaucrat
{
    public:
        Bureacrat(void);
        ~Bureacrat(void);;
        Bureacrat(const Bureacrat &object);
        Bureacrat   &operator=(const Bureacrat &object);

        std::string getName(void) const;
        std::string getGrade(void) const;
        void        incrementGrade(void);
        void        decrementGrade(void);

    private:
        const std::string   name;
        int                 grade;
};

ostream &operator=(ostream &stream, const Bureacrat &object);

#endif