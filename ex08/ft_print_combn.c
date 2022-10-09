/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 15:39:45 by tayou             #+#    #+#             */
/*   Updated: 2022/10/09 23:05:14 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	initialize(int n, int *number)
{
	int	i;

	i = 0;
	while (i < n)
	{
		number[i] = i;
		i++;
	}
}

void	get_max(int n, int *max)
{
	int	i;
	int	gps;

	gps = n - 1;
	i = 0;
	while (i < n)
	{	
		max[gps - i] = 9 - i;
		i++;
	}
}

void	print_number(int n, int *number, char *digit, int *max)
{
	int	i;

	i = 0;
	while (i < n)
	{
		digit[i] = number[i] + '0';
		i++;
	}
	write(1, digit, i);
	if (digit[0] != max[0] + '0')
		write(1, ", ", 2);
	else
		return ;
}

void	fill_number(int n, int *number, int *max, char *digit)
{
	int	point;

	point = n - 1;
	while (point >= 0)
	{
		number[point]++;
		while (point < n - 1)
		{
			number[point + 1] = number[point] + 1;
			point++;
		}
		while (number[point] <= max[point])
		{
			print_number(n, number, digit, max);
			number[point]++;
		}
		number[point]--;
		while (number[point] == max[point])
			point--;
	}					
}

void	ft_print_combn(int n)
{
	int		number[10];
	int		max[10];
	char	digit[10];

	initialize(n, number);
	get_max(n, max);
	print_number(n, number, digit, max);
	fill_number(n, number, max, digit);
}
/*
int	main()
{
	int	i;
	
	i = 1;
	while (i < 10)
	{	
		ft_print_combn(i);
		write(1, "\n", 2);
		write(1, "\n", 2);
		i++;
	}

	return 0;
}
*/
