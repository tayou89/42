#ifndef WRONG_ANIMAL_HPP
# define WRONG_ANIMAL_HPP

# include <string>

class	WrongAnimal
{
	public:
		WrongAnimal(void);
		virtual ~WrongAnimal(void);
		WrongAnimal(const WrongAnimal &object);
		WrongAnimal	&operator=(const WrongAnimal &object);

		void	makeSound(void) const;
		std::string		getType(void) const;
	protected:
		std::string	type;
		
};

#endif
