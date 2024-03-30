#include "easyfind.hpp"
#include <iostream>
#include <vector>
#include <list>
#include <deque>

template <typename Iterator>
void	printIterator(Iterator iterator)
{
	std::cout << "Iterator value: " << *iterator << '\n';
}

template <typename Container>
void	tryEasyFind(Container container, int value)
{
	typename Container::iterator	iterator;
	try
	{
		iterator = easyfind(container, value);
		printIterator(iterator);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

int	main(void)
{
	int					numbers[] = {5, 4, 7, 2, 8};
	std::vector<int>	vector(numbers, numbers + sizeof(numbers) / sizeof(int));
	std::list<int>		list(numbers, numbers + sizeof(numbers) / sizeof(int));
	std::deque<int>		deque(numbers, numbers + sizeof(numbers) / sizeof(int));
	
	tryEasyFind(vector, 2);
	std::cout << '\n';

	tryEasyFind(list, 7);
	std::cout << '\n';

	tryEasyFind(deque, 2);
	std::cout << '\n';

	tryEasyFind(vector, 10);
	std::cout << '\n';

	return (0);
}