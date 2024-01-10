#include "Span.hpp"
#include <iostream>

int	main(void)
{
	Span	sp = Span(5);

	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);

	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
	return (0);
}

// void	testSpan1(void);
// void	testSpan2(void);
// void	testSpan3(void);
// void	testSpan4(void);

// int	main(void)
// {
// 	testSpan1();
// 	testSpan2();
// 	testSpan3();
// 	testSpan4();
// 	return (0);
// }

// void	testSpan1(void)
// {
// 	Span	span(5);

// 	std::cout << "\n================== Span Test 1 ===================\n";
// 	span.addNumber(6);
// 	span.addNumber(3);
// 	span.addNumber(17);
// 	span.addNumber(9);
// 	span.addNumber(11);
// 	try
// 	{
// 		span.addNumber(13);
// 		std::cout << "Adding number success.\n";
// 	}
// 	catch(const std::exception& e)
// 	{
// 		std::cerr << e.what() << '\n';
// 	}
// }

// void	testSpan2(void)
// {
// 	unsigned int	spanSize = 10000;
// 	Span			span(spanSize);
// 	unsigned int	i;

// 	std::cout << "\n================== Span Test 2 ===================\n";
// 	std::cout << "Span max size: " << span.getMaxSize() << '\n';
// 	std::cout << "Number of integers in span: " << span.getIntegers().size() << '\n';
// 	std::srand(std::time(NULL));
// 	for (i = 0; i < span.getMaxSize(); i++)
// 		span.addNumber(std::rand() % spanSize);
// 	std::cout << "Numbers are fully added to span.\n";
// 	std::cout << "Number of integers in span: " << span.getIntegers().size() << '\n';
// 	std::cout << "Shortest span: " << span.shortestSpan() << '\n';
// 	std::cout << "Longest span: " << span.longestSpan() << '\n';
// }

// void	testSpan3(void)
// {
// 	Span				span(20);
// 	int					numbers[] = {5, 4, 2, 8, 7, 13, 27, 31, 199, 75, 643, 23, 22, 17};
// 	std::vector<int>	numberContainer(numbers, numbers + sizeof(numbers) / sizeof(int));

// 	std::cout << "\n================== Span Test 3 ===================\n";
// 	std::cout << "Span max size: " << span.getMaxSize() << '\n';
// 	span.addNumber(6);
// 	span.addNumber(3);
// 	span.addNumber(17);
// 	span.addNumber(9);
// 	span.addNumber(11);
// 	std::cout << "Number of integers in span: " << span.getIntegers().size() << '\n';
// 	try
// 	{
// 		span.addManyNumbers(numberContainer);
// 		std::cout << sizeof(numbers) / sizeof(int) << " numbers are added.\n";
// 	}
// 	catch(const std::exception& e)
// 	{
// 		std::cerr << e.what() << '\n';
// 	}
// 	std::cout << "Number of integers in span: " << span.getIntegers().size() << '\n';
// }

// void	testSpan4(void)
// {
// 	Span			span(5);
// 	unsigned int	spanResult;;

// 	std::cout << "\n================== Span Test 4 ===================\n";
// 	std::cout << "Span max size: " << span.getMaxSize() << '\n';
// 	span.addNumber(6);
// 	try
// 	{
// 		spanResult = span.shortestSpan();
// 		std::cout << "Shortest span: " << spanResult << '\n';
// 	}
// 	catch(const std::exception& e)
// 	{
// 		std::cerr << e.what() << '\n';
// 	}
// 	try
// 	{
// 		spanResult = span.longestSpan();
// 		std::cout << "Longest span: " << spanResult << '\n';
// 	}
// 	catch(const std::exception& e)
// 	{
// 		std::cerr << e.what() << '\n';
// 	}
// }