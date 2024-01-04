#include "iter.hpp"
#include <iostream>

template <typename T>
void	function(T data)
{
	std::cout << data << '\n';
}

int	main(void)
{
	int			intArray[] = { 1, 2, 3, 4, 5, 6, 7 };
	char		charArray[] = { 'a', 'b', 'c', 'd', 'e', 'f' };
	std::string	stringArray[] = { "aaa", "bbb", "ccc", "ddd", "eee" };

	iter(intArray, sizeof(intArray) / sizeof(int), function<int>);
	iter(charArray, sizeof(charArray) / sizeof(char), function<char>);
	iter(stringArray, sizeof(stringArray) / sizeof(std::string), function<std::string>);
	return (0);
}