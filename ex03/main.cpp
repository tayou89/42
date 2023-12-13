#include "MateriaSource.hpp"
#include "Character.hpp"
#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

int main(void)
{
    MateriaSource   sampleMateriaSource = makeSampleMateriaSource();;
    IMateriaSource  *materiaSourcePTR 
					= new MateriaSource(sampleMateriaSource);

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

MateriaSource	makeSampleMateriaSource(void)
{
	MateriaSource	materiaSource();

	materiaSource.createMateria("ice");
	materiaSource.leanrMateria(new Ice());
	materiaSource.learnMateria(new Ice());
	materiaSource.learnMateria(new Cure());
	materiaSource.learnMateria(new Cure());
	materiaSource.learnMateria(new Cure());
}