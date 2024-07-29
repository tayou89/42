/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 15:17:50 by tayou             #+#    #+#             */
/*   Updated: 2022/10/19 20:00:53 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int			*array;
	int			i;
	long long	size;

	if (min >= max)
		return (0);
	size = max - min;
	array = (int *) malloc(size * sizeof(int));
	if (array == 0)
		return (-1);
	i = 0;
	while (min < max)
	{
		array[i] = min;
		i++;
		min++;
	}
	*range = array;
	return (size);
}
/*
#include <stdio.h>

int	main()
{
	int	**range;
	int	min;
	int	max;
	long long	size;

	min = 4;
	max = 9;
	size = ft_ultimate_range(range, min, max);
	printf("%lld\n", size);
}
*/
