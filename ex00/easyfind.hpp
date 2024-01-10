#ifndef EASY_FIND_HPP
# define EASY_FIND_HPP

# include <algorithm>
# include <stdexcept>

template <typename Container>
typename Container::iterator	easyfind(Container container, int value)
{
	typename Container::iterator	findReturn;

	findReturn = std::find(container.begin(), container.end(), value);
	if (findReturn != container.end())
		return (findReturn);
	else
		throw (std::runtime_error("Failed to find value"));
}

#endif