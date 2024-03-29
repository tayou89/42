/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 19:51:51 by tayou             #+#    #+#             */
/*   Updated: 2022/10/09 22:03:52 by tayou            ###   ########.fr       */
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


void	get_count(char (*arr)[4], int *count, int *k)
{
	int i;
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

void	make_arr(char (*arr)[4])
{
	int	i;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (arr[i][j] == '0')
				arr[i][j] = {'1', '2', '3', '4'};
			j++;
		}
		i++;
	}
}

void	check_four_rowright(char *rowright, char (*arr)[4])
{
	int	i;
	int	j;
	int	k;

	i = 0;
	while (i < 4)
	{
		if (rowright[i] == 4)
		{
			j = 3;
			k = 0;
			while (j >= 0)
			{
				arr[i][j] = k + '1';
				k++;
				j--;
			}
		}
		else if (rowright[i] == 1)
			arr[i][3] = 4 + '0';
		i++;
	}
}

void	check_four_rowleft(char *rowleft, char (*arr)[4])
{
	int	i;
	int	j;

	i = 0;
	while (i < 4)
	{
		if (rowleft[i] == 4)
		{
			j = 0;
			while (j < 4)
			{
				arr[i][j] = j + '1';
				j++;
			}
		}
		else if (rowleft[i] == 1)
			arr[i][0] = 4 + '0';
		i++;
	}
}

void	check_four_coldown(char *coldown, char (*arr)[4])
{
	int	i;
	int	j;
	int	k;

	i = 0;
	while (i < 4)
	{
		if (coldown[i] == 4)
		{
			j = 3
			k = 0;
			while (j >= 0 )
			{
				arr[j][i] = k + '1'; 
				k++;
				j--;
			}
		}
		else if (coldown[i] == 1)
			arr[3][i] = 4 + '0';
		i++;
	}
}

void	check_four_colup(char *colup, char (*arr)[4])
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (colup[i] == 4)
		{
			j = 0;
			while (j < 4)
			{
				arr[j][i] = j + '1';
				j++;
			}
		}
		else if(colup[i] == 1)
			arr[0][i] = 4 + '0';
		i++;
	}
}

void	initialize(char (*arr)[4])
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < 4)
	{
		while (j < 4)
		{
			arr[i][j] = '0';
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
		check_four_colup(colup, arr);
		check_four_coldown(coldown, arr);
		check_four_rowup(rowup, arr);
		check-four_rowdown(rowdown, arr);
		make_arr(arr);
		check_size(arr); 
		print(arr);
	}
	return 0;
}
