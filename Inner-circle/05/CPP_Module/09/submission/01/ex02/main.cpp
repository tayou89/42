#include "PmergeMe.hpp"
#include <iostream>

int	main(int argc, char *argv[])
{
	(void) argc;
	try
	{
		PmergeMe	pMergeMe;

		pMergeMe.sortByVectorContainer(&argv[1]);
		pMergeMe.sortByDequeContainer(&argv[1]);
		pMergeMe.printSortResult();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return (0);
}