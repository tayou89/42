#ifndef ITER_HPP
# define ITER_HPP

# include <cstdlib>

template <typename T1, typename T2>
void	iter(T1 *array, size_t arrayLength, T2 function)
{
	if (array == NULL)
		return ;
	for (size_t i = 0; i < arrayLength; i++)
		function(array[i]);
}

#endif