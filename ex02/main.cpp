#include <iostream>
#include <vector>

void	binaryInsertionSort(std::vector<int> &vector);
int	binarySearch(std::vector<int> &vector, int first, int last, int target);

int	main()
{
	int							array[] = {8, 3, 5, 2, 9};
	std::vector<int>			vector(array, array + sizeof(array) / sizeof(int));
	std::vector<int>::iterator	iterator;

	for (iterator = vector.begin(); iterator != vector.end(); iterator++)
		std::cout << *iterator << ' ';
	std::cout << '\n';
	binaryInsertionSort(vector);
	for (iterator = vector.begin(); iterator != vector.end(); iterator++)
		std::cout << *iterator << ' ';
	std::cout << '\n';
	return (0);
}

void	binaryInsertionSort(std::vector<int> &vector)
{
	int		insertIndex;
	int		target;
	size_t	i;

	for (i = 1; i < vector.size(); i++)
	{
		target = vector[i];
		insertIndex = binarySearch(vector, 0, i - 1, target);
		vector.erase(vector.begin() + i);
		if (target < vector[insertIndex])
			vector.insert(vector.begin() + insertIndex, target);
		else
			vector.insert(vector.begin() + insertIndex + 1, target);
	}
}

int	binarySearch(std::vector<int> &vector, int first, int last, int target)
{
	int	mid;

	if (last <= first)
		return (first);
	mid = (first + last) / 2;
	if (target < vector[mid])
		return (binarySearch(vector, first, mid - 1, target));
	else
		return (binarySearch(vector, mid + 1, last, target));
}