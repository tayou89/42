#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <string>

class	Brain
{
	public:
		Brain(void);
		~Brain(void);
		Brain(const Brain &object);
		Brain	&operator=(const Brain &object);

	private:
		std::string	ideas[100];
};

#endif
