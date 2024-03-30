#ifndef MATERIA_SOURCE_HPP
# define MATERIA_SOURCE_HPP

# include <string>
# include "IMateriaSource.hpp"
# include "AMateria.hpp"

class   MateriaSource : public IMateriaSource
{
    public:
        MateriaSource(void);
        virtual ~MateriaSource(void);
        MateriaSource(const MateriaSource &object);
        MateriaSource   	&operator=(const MateriaSource &object);

        virtual void        learnMateria(AMateria *aMateriaPTR);
        virtual AMateria    *createMateria(std::string const &type);

    private:
		void		_deleteMateriaSource(int idx);

        const int   _materiaMaxCount;
        AMateria    *_materia[4];

};

#endif