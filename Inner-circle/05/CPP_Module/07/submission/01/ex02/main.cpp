#include <iostream>
#include "Array.hpp"

template <typename T>
void	printArray(Array<T> array, const char *name);
template <typename T>
void	fillArray(Array<T> &array, T data);

int	main(void)
{
	Array<int>			A;
	Array<char> 		B(6);
	Array<int>			C(6);

	printArray(A, "A");
	printArray(B, "B");

	//A[10] = 4;

	fillArray(A, 3);
	fillArray(B, 'c');
	fillArray(C, 10);
	const Array<char> 	D(B);

	printArray(A, "A");
	printArray(B, "B");
	printArray(C, "C");

	A = C;
	std::cout << "\'A = C\' has been occured.\n\n";

	printArray(A, "A");
	printArray(D, "D");
	//D[3] = 'a';
	return (0);
}

template <typename T>
void	printArray(Array<T> array, const char *name)
{
	unsigned int 	i;

	std::cout << "Array " << name << " size: " << array.size() << '\n';
	for (i = 0; i < array.size(); i++)
		std::cout << name << '[' << i << "]: " << array[i] << "\n";
	std::cout << '\n';
}

template <typename T>
void	fillArray(Array<T> &array, T data)
{
	unsigned int	i;

	for (i = 0; i < array.size(); i++)
		array[i] = data;
}