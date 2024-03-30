#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class	Dog : public Animal
{
	public:
		Dog(void);
		~Dog(void);
		Dog(const Dog &object);
		Dog	&operator=(const Dog &object);

		Dog(const std::string *ideas, const int ideaCount);
		virtual void		makeSound(void) const;
		virtual void		setBrainIdea(std::string idea);
		virtual std::string	getBrainIdea(const int ideaIndex) const;
		virtual int			getBrainIdeaCount(void) const;
		virtual void		*getBrainPTR(void) const;

	private:
		Brain	*brainPTR;
};

#endif