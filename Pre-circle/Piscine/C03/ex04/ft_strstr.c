/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 05:40:31 by tayou             #+#    #+#             */
/*   Updated: 2022/10/14 20:34:47 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	check_word(char *str, char *to_find, int same_point)
{
	int	i;
	int	j;

	i = same_point;
	j = 0;
	while (to_find[j] != '\0' && str[i] == to_find[j])
	{
		i++;
		j++;
	}
	if (to_find[j] == '\0')
		return (1);
	else
		return (0);
}

char	*ft_strstr(char *str, char *to_find)
{	
	int	i;
	int	same_point;

	if (to_find[0] == '\0')
		return (str);
	i = 0;
	while (str[i] != '\0')
	{
		if (to_find[0] == str[i])
		{
			same_point = i;
			if (check_word(str, to_find, same_point) == 1)
				return (&str[same_point]);
		}
		i++;
	}
	return ((char *) '\0');
}
/*
#include <stdio.h>
#include <string.h>

int	main()
{
	char	str1[] = "aabc";
	char	str2[] = "aabc";
	char	to_find[] = "adf";

	printf("stsstr : %s\n", strstr(str1, to_find));
	printf("ft_strstr : %s\n", ft_strstr(str2, to_find));

	return (0);
}
*/
