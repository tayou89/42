#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include "TypeIdentifier.hpp"
#include <iostream>

int	main(void)
{
	Base	*basePTR = generate();

	std::cout << "Type identified by pointer: ";
	identify(basePTR);

	std::cout << "Type identified by reference: ";
	identify(*basePTR);

	delete basePTR;
	return (0);
}