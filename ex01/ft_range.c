/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 14:41:47 by tayou             #+#    #+#             */
/*   Updated: 2022/10/19 20:00:32 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int			*array;
	long long	size;
	int			i;

	if (min >= max)
		return (0);
	size = max - min;
	array = (int *) malloc(size * sizeof(int));
	if (array == 0)
		return (0);
	i = 0;
	while (min < max)
	{
		array[i] = min;
		i++;
		min++;
	}
	return (array);
}
/*
#include <stdio.h>

int	main()
{
	int	min;
	int	max;
	int	i;
	int	size;
	int	*range;

	min = 9;
	max = 4;
	size = max - min;
	if(size < 0)
		size *= (-1);
	range = ft_range(min, max);
	i = 0;
	while (i < size)
	{
		printf("%d ", range[i]);
		i++;
	}
	printf("\n");
	return (0);
}
*/
