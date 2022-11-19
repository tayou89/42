/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 23:28:26 by tayou             #+#    #+#             */
/*   Updated: 2022/11/18 02:20:18 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	get_array_size(char const *s, char c)
{
	int	i;
	int	array_size;

	i = 0;
	if (s[i] == c)
		i++;
	array_size = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			array_size++;
		i++;
	}
	if (s[i - 1] != c)
		array_size++;
	return (array_size);
}

char	**free_array(char **array)
{
	int	i;

	i = 0;
	while (array[i] != NULL)
	{
		free(array[i]);
		i++;
	}
	free(array);
	return (0);
}

char	*fill_array(char *array, char const *s, int start_point, int end_point)
{
	int	i;

	i = 0;
	while (start_point <= end_point)
	{
		array[i] = s[start_point];
		start_point++;
		i++;
	}
	array[i] = '\0';
	return (array);
}

char	**get_array(char **array, char const *s, char c)
{
	int		i;
	int		k;
	int		start_point;
	int		end_point;
	int		sub_array_size;

	i = 0;
	if (s[i] == c)
		i++;
	k = 0;
	while (s[i] != '\0')
	{
		start_point = i;
		while (s[i] != c && s[i] != '\0')
			i++;
		end_point = i - 1;
		sub_array_size = end_point - start_point + 1;
		array[k] = (char *) malloc(sizeof(char) * sub_array_size + 1);
		if (array[k] == 0)
			return (free_array(array));
		array[k] = fill_array(array[k], s, start_point, end_point);
		i++;
		k++;
	}
	return (array);
}

char	**ft_split(char const *s, char c)
{
	char	**array;
	int		array_size;
	int		s_size;

	s_size = ft_strlen(s);
	if (s_size == 0)
		return (0);
	array_size = get_array_size(s, c);
	array = (char **) malloc(sizeof(char *) * (array_size + 1));
	if (array == 0)
		return (0);
	array = get_array(array, s, c);
	array[array_size] = NULL;
	return (array);
}
/*
#include <stdio.h>

int	main()
{
	char	*s = "He is a good man";
	char	c;
	char	**string_array;
	int		i;

	printf("s: %s\n", s);
	printf("c: ");
	scanf("%c", &c);
	string_array = ft_split(s, c);
	i = 0;
	while (string_array[i] != NULL)
	{
		printf("array[%d]: %s\n", i, string_array[i]);
		i++;
	}
	return (0);
}
*/
