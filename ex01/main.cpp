#include <iostream>

int	main(void)
{
	std::srand(std::time(NULL));
	int randomNumber = std::rand();
	unsigned int	i;

	for (i = 0; i < 10; i++)
	{
		randomNumber = std::rand(); 
		std::cout << "randomNumber: " << randomNumber << '\n';
	} 
	return (0);
}