#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"

class	Dog : public Animal
{
	public:
		Dog(void);
		~Dog(void);
		Dog(const Dog &object);
		Dog	&operator=(const Dog &object);

		virtual void	makeSound(void) const;
};

#endif