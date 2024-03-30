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

		std::string	getIdea(const int ideaIndex) const;
		void		setIdea(const std::string	idea);
		int			getIdeaCount(void) const;

	private:
		static const int	maxIdeaCount = 100;
		int					ideaCount;
		std::string			ideas[maxIdeaCount];
};

#endif