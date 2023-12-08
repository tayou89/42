#ifndef I_MATERIA_SOURCE_HPP
# define I_MATERIA_SOURCE_HPP

class   IMateriaSource
{
    public:
        virtual ~IMateriaSouce(void) {}
        virtual void        learnMateria(AMateria *) = 0;
        virtual AMateria    *createMateria(std::string const &type) = 0;
}

#endif