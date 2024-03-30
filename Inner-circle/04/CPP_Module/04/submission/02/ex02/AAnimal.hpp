#ifndef AANIMAL_HPP
# define AANIMAL_HPP

# include <string>

class	AAnimal
{
	public:
		AAnimal(void);
		virtual ~AAnimal(void);
		AAnimal(const AAnimal &object);
		AAnimal	&operator=(const AAnimal &object);

		virtual void	makeSound(void) const = 0;
		std::string		getType(void) const;
	protected:
		std::string	type;
		
};

#endif
