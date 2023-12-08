#ifndef DOG_HPP
# define DOG_HPP

# include "AAnimal.hpp"
# include "Brain.hpp"

class	Dog : public AAnimal
{
	public:
		Dog(void);
		~Dog(void);
		Dog(const Dog &object);
		Dog	&operator=(const Dog &object);

		virtual void	makeSound(void) const;
	
	private:
		Brain	*brainPTR;
};

#endif
