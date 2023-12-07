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
	protected:
		std::string	type;
		
};

#endif
