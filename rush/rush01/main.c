/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 19:51:51 by tayou             #+#    #+#             */
/*   Updated: 2022/10/09 22:01:07 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print(char (*arr)[4])
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < 4)
	{
		while (j < 4)
		{
			write(1, &arr[i][j], 1);
			if (j != 3)
				write(1, " ", 1);
			j++;
		}
		write(1, "\n", 2);
		i++;
	}
}

void	swap(char (*arr)[4], int *i, int *j, int *k)
{
	char	temp;

	temp = arr[*k][*i];
	arr[*k][*i] = arr[*k][*j];
	arr[*k][*j] = temp;
}

void	get_count(char (*arr)[4], int *count, int *k)
{
	int	i;
	int	j;	

	i = 0;
	j = 1;
	while (j < 4)
	{
		if (arr[*k][i] < arr[*k][j])
		{
			(*count)++;
			i = j;
			j++;
		}
		else
			j++;
	}
}

void	arrange(char (*arr)[4], char *rowleft, int *i, int *k)
{
	int	j;
	int	count;
	
	count = 1;
	*k = 0;
	while (*k < 4)
	{
		*i = 0;
		while (*i < 4)
		{
			j = (*i) + 1;
			while (j < 4)
			{
				get_count(arr, &count, k);
				if (count > rowleft[*k] && arr[*k][*i] < arr[*k][j])
					swap(arr, i, &j, k);
				else if (count < rowleft[*k] && arr[*k][*i] > arr[*k][j])
					swap(arr, i, &j, k);
				j++;
			}
			(*i)++;
		}
		(*k)++;
	}
}	
void	initialize(char (*arr)[4])
{
	int	i;
	int	j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			arr[i][j] = j + '1';
			j++;
		}
		i++;
	}
}
	
void	put_rownumber(char *rowleft, char *rowright, char **argv)
{
	int	i;
	int	j;

	i = 0;
	j = 16;
	while (i < 4)
	{
		rowleft[i] = argv[1][j];
		j += 2;
		i++;
	}
	while (i < 4)
	{
		rowright[i] = argv[1][j];
		j += 2;
		i++;
	}
}

void	put_colnumber(char *colup, char *coldown, char **argv)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < 4)
	{
		colup[i] = argv[1][j];
		j += 2;
		i++;
	}
	i = 0;
	while (i < 4)
	{
		coldown[i] = argv[1][j];
		j += 2;
		i++;
	}
}

int	main(int argc, char *argv[])
{
	char	arr[4][4];
	char	colup[4];
	char 	coldown[4];
	char	rowleft[4];
	char	rowright[4];
	int		i;
	int		k;

	i = 0;
	k = 0;
	if (argc == 2)
	{
		put_colnumber(colup, coldown, argv);
		put_rownumber(rowleft, rowright, argv);
		initialize(arr);
		arrange(arr, rowleft, &i, &k);
		print(arr);
	}
	return 0;
}
