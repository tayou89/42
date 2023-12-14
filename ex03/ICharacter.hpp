#ifndef I_CHARACTER_HPP
# define I_CHARACTER_HPP

# include <string>

class	AMateria;

class	ICharacter
{
	public:
		ICharacter(void);
		virtual ~ICharacter(void);
		ICharacter(const ICharacter &object);
		ICharacter	&operator=(const ICharacter &object);

		virtual std::string	const	&getName(void) const = 0;
		virtual void				equip(AMateria *m) = 0;				
		virtual void				unequip(int idx) = 0;
		virtual void				use(int idx, ICharacter &target) = 0;
};

#endif
