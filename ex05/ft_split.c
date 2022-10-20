/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 14:36:49 by tayou             #+#    #+#             */
/*   Updated: 2022/10/20 00:12:31 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	check_string(char *str, char *charset, int *i)
{
	int	j;

	j = 0;
	while (charset[j] != '\0')
		j++;
	while (charset[j] == '\0' && str[*i] != '\0')
	{
		j = 0;
		while (charset[j] != '\0')
		{
			if (charset[j] == str[*i])
				return ;
			else
				j++;
		}
		(*i)++;
	}
}

void	check_charset(char *str, char *charset, int *i)
{
	int	j;

	j = 0;
	while (charset[j] != '\0' && str[*i] != '\0')
	{
		if (charset[j] == str[*i])
		{
			(*i)++;
			j = 0;
		}
		else
			j++;
	}
}

void	fill_array(char *array, char *str, int start_point, int end_point)
{
	int	i;

	i = 0;
	while (start_point < end_point)
	{
		array[i] = str[start_point];
		i++;
		start_point++;
	}
	array[i] = '\0';
}

char	**malloc_array(char **array, char *str, char *charset)
{
	int	i;
	int	k;
	int	start_point;
	int	end_point;
	int	size;

	i = 0;
	k = 0;
	while (str[i] != '\0')
	{
		check_charset(str, charset, &i);
		start_point = i;
		check_string(str, charset, &i);
		end_point = i;
		size = end_point - start_point;
		array[k] = (char *) malloc(sizeof(char) * size + 1);
		if (array[k] == 0)
			return (0);
		fill_array(array[k], str, start_point, end_point);
		k++;
	}
	return (array);
}

char	**ft_split(char *str, char *charset)
{
	int		i;
	int		count;
	char	**array;

	count = 0;
	i = 0;
	while (str[i] != '\0')
	{
		check_charset(str, charset, &i);
		if (str[i] == '\0')
			break ;
		check_string(str, charset, &i);
		count++;
	}
	array = (char **) malloc(sizeof(char *) * count + 1);
	if (array == 0)
		return (0);
	array = malloc_array(array, str, charset);
	array[count] = 0;
	return (array);
}
/*
#include <stdio.h>

int	main()
{
	char	*str = " abc def ghi jkl ";
	char	*charset = " ";
	char	**array;
	int		i;

	array = ft_split(str, charset);
	i = 0;
	while (array[i] != (void *)'\0')
	{
		printf("array[%d] : %s\n", i, array[i]);
		i++;
	}
	return (0);
}
*/
