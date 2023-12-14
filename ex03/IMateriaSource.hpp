#ifndef I_MATERIA_SOURCE_HPP
# define I_MATERIA_SOURCE_HPP

# include <string>
# include "AMateria.hpp"

class   IMateriaSource
{
    public:
		IMateriaSource(void);
        virtual ~IMateriaSource(void);
		IMateriaSource(const IMateriaSource &object);
		IMateriaSource	&operator=(const IMateriaSource &object);

        virtual void        learnMateria(AMateria *) = 0;
        virtual AMateria    *createMateria(std::string const &type) = 0;
};

#endif
