#include "PmergeMe.hpp"
#include <iostream>

int	main(int argc, char *argv[])
{
	(void) argc;
	try
	{
		PmergeMe	pMergeMe(&argv[1]);

		pMergeMe.sortByVectorContainer();
		pMergeMe.printVectorInputIntegers();
		std::cout << '\n';
		pMergeMe.printVectorMainChain();
		std::cout << '\n';
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	return (0);
}