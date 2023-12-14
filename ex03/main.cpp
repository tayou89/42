#include "MateriaSource.hpp"
#include "Character.hpp"
#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

int main(void)
{
    IMateriaSource  *src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());

    ICharacter  *me = new Character("me");

    AMateria    *temp;

    temp = src->createMateria("ice");
    me->equip(temp);
    temp = src->createMateria("cure");
    me->equip(temp);

    ICharacter  *bob = new Character("bob");

    me->use(0, *bob);
    me->use(1, *bob);

    delete  bob;
    delete  me;
    delete  src;

    return (0);
}
