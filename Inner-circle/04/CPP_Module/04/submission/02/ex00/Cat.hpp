#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"

class	Cat : public Animal
{
	public:
		Cat(void);
		~Cat(void);
		Cat(const Cat &object);
		Cat	&operator=(const Cat &object);
	
		virtual	void	makeSound(void) const;	
};
#endif