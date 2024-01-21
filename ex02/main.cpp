#include "PmergeMe.hpp"
#include <iostream>

int	main(int argc, char *argv[])
{
	(void) argc;
	try
	{
		PmergeMe	pMergeMe;

		pMergeMe.sortByVectorContainer(&argv[1]);
		pMergeMe.printVectorMainChain(); std::cout << '\n';
		std::cout << "Vector ElapsedTime: " << pMergeMe.getVectorElapsedTime() << "\n\n"; 

		pMergeMe.sortByDequeContainer(&argv[1]);
		pMergeMe.printDequeMainChain(); std::cout << '\n';
		std::cout << "Deque ElapsedTime: " << pMergeMe.getDequeElapsedTime() << '\n';
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	return (0);
}