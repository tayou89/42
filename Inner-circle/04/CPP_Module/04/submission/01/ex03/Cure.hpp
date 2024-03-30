#ifndef CURE_HPP
# define CURE_HPP

# include "AMateria.hpp"
# include "ICharacter.hpp"

class   Cure : public AMateria
{
    public:
        Cure(void);
        virtual ~Cure(void);
        Cure(const Cure &object);
        Cure &operator=(const Cure &object);

        virtual AMateria    *clone(void) const;
        virtual void        use(ICharacter &target);
};

#endif
