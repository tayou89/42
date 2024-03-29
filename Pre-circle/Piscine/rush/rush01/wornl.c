#include <unistd.h>

void	recurs(int depth, int n, char *arr)
{
	int idx;

	idx = 1;
	if (depth == n)
	{
		write (1, arr, depth);
		return ;
	}
	while (idx < 5)
	{
		if (depth != 0 && arr[depth -1] != idx + '0')
		{
			idx++;
			continue ;
		}
		arr[depth] = idx + '0';
		recurs(depth +1, n, arr);
		idx++;
	}
}

int	main(int ac, char **av)
{
	char arr[16];
	if (ac == 2)
	{
		recurs(0, 16, arr, av);
	}
	return (0);
}



https://cocoon1787.tistory.com/217
