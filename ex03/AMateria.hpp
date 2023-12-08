#ifndef A_MATERIA_HPP
# define A_MATERIA_HPP

# include <string>

class	AMateria
{
	protected:
		std::string	type;

	public:
		AMateria(void);
		virtual	~AMateria(void);
		AMateria(const AMateria &object);
		AMateria	&operator=(const AMateria &object);

		std::string const	&getType(void) const;
		virtual AMateria	*clone(void) const = 0;
		virtual void		use(ICharacter &target);
};

#endif
