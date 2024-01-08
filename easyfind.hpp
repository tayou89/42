#ifndef EASY_FIND_HPP
# define EASY_FIND_HPP

# include <typeinfo>
# include <algorithm>
# include <stdexcept>

template <typename Container>
typename Container::iterator	easyfind(Container container, int value)
{
	typename Container::iterator	findReturn;;

	if (typeid(typename Container::value_type) != typeid(int))
		throw (std::invalid_argument("Failed to find value: type is not integer"));
	findReturn = std::find(container.begin(), container.end(), value);
	if (findReturn != container.end())
		return (findReturn);
	else
		throw (std::runtime_error("Failed to find value: value does not exist in container"));
}

#endif