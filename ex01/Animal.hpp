#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <string>

class	Animal
{
	public:
		Animal(void);
		virtual ~Animal(void);
		Animal(const Animal &object);
		Animal	&operator=(const Animal &object);

		virtual void	makeSound(void) const;
		std::string		getType(void) const;

		virtual void		setBrainIdea(std::string idea) = 0;
		virtual std::string	getBrainIdea(const int ideaIndex) const = 0;
		virtual int			getBrainIdeaCount(void) const = 0;
		virtual	void		*getBrainPTR(void) const = 0;

	protected:
		std::string	type;
		
};

#endif
