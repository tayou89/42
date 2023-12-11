#ifndef ICE_HPP
# define ICE_HPP

# include "AMateria.hpp"
# include "ICharacter.hpp"

class   Ice : public AMateria
{
    public:
        Ice(void);
        virtual ~Ice(void);
        Ice(const Ice &object);
        Ice &operator=(const Ice &object);

        virtual AMateria    *clone(void) const;
        virtual void        use(ICharacter &target);
};

#endif
