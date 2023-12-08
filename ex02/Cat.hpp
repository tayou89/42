#ifndef CAT_HPP
# define CAT_HPP

# include "AAnimal.hpp"
# include "Brain.hpp"

class	Cat : public AAnimal
{
	public:
		Cat(void);
		~Cat(void);
		Cat(const Cat &object);
		Cat	&operator=(const Cat &object);
	
		virtual	void	makeSound(void) const;	

	private:
		Brain	*brainPTR;
};

#endif
