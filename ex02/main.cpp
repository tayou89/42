#include <iostream>
#include "Array.hpp"

int	main(void)
{
	Array<int>		A;
	Array<char> 	B(20);
	Array<int>		C(20);
	Array<char> 	D(B);
	unsigned int	i;

	std::cout << "Array A size: " << A.size() << '\n';
	for (i = 0; i < A.size(); i++)
		std::cout << "A[" << i << "]: " << A[i] << '\n';
	std::cout << '\n';
	//std::cout << "A[" << i << "]: " << A[i] << '\n';

	std::cout << "Array B size: " << B.size() << '\n';
	for (i = 0; i < B.size(); i++)
		std::cout << "B[" << i << "]: " << B[i] << '\n';
	std::cout << '\n';
	//std::cout << "B[" << i << "]: " << B[i] << '\n';

	A = C;
	std::cout << "Array A size: " << A.size() << '\n';
	for (i = 0; i < A.size(); i++)
		std::cout << "A[" << i << "]: " << A[i] << '\n';
	std::cout << '\n';

	std::cout << "Array D size: " << D.size() << '\n';
	for (i = 0; i < B.size(); i++)
		std::cout << "D[" << i << "]: " << D[i] << '\n';
	return (0);
}