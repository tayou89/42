#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class	Cat : public Animal
{
	public:
		Cat(void);
		~Cat(void);
		Cat(const Cat &object);
		Cat	&operator=(const Cat &object);
	
		Cat(const std::string *ideas, const int ideaCount);
		virtual	void		makeSound(void) const;	
		virtual void		setBrainIdea(std::string idea);
		virtual std::string	getBrainIdea(const int ideaIndex) const;
		virtual int			getBrainIdeaCount(void) const;
		virtual void		*getBrainPTR(void) const;

	private:
		Brain	*brainPTR;
};

#endif
