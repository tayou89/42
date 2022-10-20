/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 16:54:38 by tayou             #+#    #+#             */
/*   Updated: 2022/10/20 17:32:36 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	get_sep_size(int size, char *sep)
{
	int	i;
	int	j;
	int	sep_size;

	sep_size = 0;
	i = 0;
	while (i < size - 1)
	{
		j = 0;
		while (sep[j] != '\0')
		{
			j++;
		}
		sep_size += j;
		i++;
	}
	return (sep_size);
}	

int	get_strs_size(int size, char **strs)
{
	int	i;
	int	j;
	int	strs_size;

	strs_size = 0;
	i = 0;
	while (i < size)
	{
		j = 0;
		while (strs[i][j] != '\0')
		{
			j++;
		}
		strs_size += j;
		i++;
	}
	return (strs_size);
}

void	fill_array_sep(char *sep, char *array, int *k)
{
	int	i;

	i = 0;
	while (sep[i] != '\0')
	{
		array[*k] = sep[i];
		i++;
		(*k)++;
	}
}

void	fill_array(int size, char **strs, char *sep, char *array)
{
	int	i;
	int	j;
	int	k;

	k = 0;
	i = 0;
	while (i < size)
	{
		j = 0;
		while (strs[i][j] != '\0')
		{
			array[k] = strs[i][j];
			k++;
			j++;
		}
		if (i == size - 1)
			return ;
		else
			fill_array_sep(sep, array, &k);
		i++;
	}
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*array;
	int		strs_size;
	int		sep_size;
	int		total_size;

	if (size == 0)
	{
		array = (char *)malloc(1);
		array[0] = '\0';
		return (array);
	}
	strs_size = get_strs_size(size, strs);
	sep_size = get_sep_size(size, sep);
	total_size = strs_size + sep_size;
	array = (char *) malloc(total_size * sizeof(char) + 1);
	if (array == 0)
		return (0);
	fill_array(size, strs, sep, array);
	array[total_size] = '\0';
	return (array);
}
/*
#include <stdio.h>

int	main()
{
	char	*strs[4];
	char	*sep = " : ";
	char	*array;
	int		size;

	strs[0] = "abcd";
	strs[1] = "efg";
	strs[2] = "hijk";
	strs[3] = "lmnop";
	size = 0;
	array = ft_strjoin(size, strs, sep);
	printf("strs[0] : %s\n", strs[0]);
	printf("strs[1] : %s\n", strs[1]);
	printf("strs[2] : %s\n", strs[2]);
	printf("stsrs[3] : %s\n", strs[3]);
	printf("sep : %s\n", sep);
	printf("array : %s\n", array);
	return (0);
}
*/
