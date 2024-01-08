#include "easyfind.hpp"
#include <iostream>
#include <vector>
#include <list>
#include <array>
#include <deque>
#include <forward_list>
#include <typeinfo>

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
	int						numbers[] = {5, 4, 7, 2, 8};
	std::array<char, 5>		charArray = {'c', 'a', 'd', 'e', 'f'};
	std::array<int, 5>		intArray = {5, 4, 7, 2, 8};
	std::vector<int>		vector(numbers, numbers + sizeof(numbers) / sizeof(int));
	std::list<int>			list(numbers, numbers + sizeof(numbers) / sizeof(int));
	std::deque<int>			deque(numbers, numbers + sizeof(numbers) / sizeof(int));
	std::forward_list<int>	forward_list(numbers, numbers + sizeof(numbers) / sizeof(int));

	tryEasyFind(intArray, 5);
	std::cout << '\n';
	
	tryEasyFind(vector, 2);
	std::cout << '\n';

	tryEasyFind(list, 7);
	std::cout << '\n';

	tryEasyFind(deque, 2);
	std::cout << '\n';

	tryEasyFind(forward_list, 8);
	std::cout << '\n';

	tryEasyFind(intArray, 10);
	std::cout << '\n';

	tryEasyFind(charArray, 'c');
	std::cout << '\n';
	return (0);
}