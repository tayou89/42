#include <iostream>
#include "MateriaSource.hpp"
#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

MateriaSource	makeSampleMateriaSource(void);
Character       makeSampleCharacter(IMateriaSource *materiaSourcePTR);

int main(void)
{
    MateriaSource   sampleMateriaSource = makeSampleMateriaSource();;
    IMateriaSource  *materiaSRC
					= new MateriaSource(sampleMateriaSource);

    Character   sampleCharacter = makeSampleCharacter(materiaSRC);
    ICharacter  *me = new Character(sampleCharacter); 
    ICharacter  *bob = new Character("bob");

	AMateria	*aMateriaPTR = NULL;

    me->use(0, *bob);
    me->use(1, *bob);
    me->use(2, *bob);
    me->use(3, *bob);
    std::cout << std::endl;

    aMateriaPTR = materiaSRC->createMateria("cure");
    me->equip(aMateriaPTR);
    me->use(3, *me);
    delete aMateriaPTR;
	me->unequip(3);
    me->use(3, *me);

    delete  bob;
    delete  me;
    delete  materiaSRC;

    return (0);
}

MateriaSource	makeSampleMateriaSource(void)
{
	MateriaSource	materiaSource;

    std::cout << "************** makeSampleMateriaSource *************\n\n";
	materiaSource.createMateria("ice");
    materiaSource.learnMateria(NULL);
	materiaSource.learnMateria(new Ice());
	materiaSource.learnMateria(new Ice());
	materiaSource.learnMateria(new Cure());
	materiaSource.learnMateria(new Cure());
	materiaSource.learnMateria(new Cure());
    std::cout << std::endl;
    return (materiaSource);
}

Character   makeSampleCharacter(IMateriaSource *materiaSourcePTR)
{
    Character   sampleCharacter("me");

    std::cout << "************** makeSampleCharacter *************\n\n";
    sampleCharacter.equip(NULL);
    sampleCharacter.equip(materiaSourcePTR->createMateria("abc"));
    sampleCharacter.equip(materiaSourcePTR->createMateria("ice"));
    sampleCharacter.equip(materiaSourcePTR->createMateria("ice"));
    sampleCharacter.equip(materiaSourcePTR->createMateria("cure"));
    std::cout << std::endl;
    return (sampleCharacter);
}
