#include "TypeIdentifier.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

Base	*generate(void)
{
	std::srand(std::time(NULL));
	int randomNumber = std::rand() % 3;

	switch(randomNumber)
	{
		case 0:
			return (new A());
			break ;
		case 1:
			return (new B());
			break ;
		default :
			return (new C());
	}	
}

void	identify(Base *p)
{
	A	*aPTR = dynamic_cast<A*>(p);
	B	*bPTR = dynamic_cast<B*>(p);
	C	*cPTR = dynamic_cast<C*>(p);

	if (aPTR != NULL)
		std::cout << "A" << '\n';
	if (bPTR != NULL)
		std::cout << "B" << '\n';
	if (cPTR != NULL)
		std::cout << "C" << '\n';
}

void	identify(Base &p)
{
	try
	{
		(void) dynamic_cast<A&>(p);
		std::cout << "A" << '\n';
	}
	catch (const std::exception &exception)
	{
	}

	try
	{
		(void) dynamic_cast<B&>(p);
		std::cout << "B" << '\n';
	}
	catch (const std::exception &exception)
	{
	}
	
	try
	{
		(void) dynamic_cast<C&>(p);
		std::cout << "C" << '\n';
	}
	catch (const std::exception &exception)
	{
	}
}