/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 20:15:09 by tayou             #+#    #+#             */
/*   Updated: 2023/01/07 14:30:22 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*malloc_overstart(void)
{
	char	*string;

	string = (char *) malloc(sizeof(char));
	if (string == 0)
		return (0);
	string[0] = '\0';
	return (string);
}

size_t	get_size(size_t necessary_size, size_t len)
{
	if (necessary_size <= len)
		return (necessary_size);
	else
		return (len);
}

char	*fill_sub(char *string, char *s, size_t start, size_t actual_size)
{
	size_t	i;

	i = 0;
	while (i < actual_size)
	{
		string[i] = s[start];
		start++;
		i++;
	}
	string[i] = '\0';
	return (string);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substring;
	size_t	s_len;
	size_t	necessary_size;
	size_t	actual_size;

	s_len = ft_strlen(s);
	if (start > s_len)
	{
		substring = malloc_overstart();
		return (substring);
	}
	necessary_size = s_len - start;
	actual_size = get_size(necessary_size, len);
	substring = (char *) malloc(sizeof(char) * actual_size + 1);
	if (substring == 0)
		return (0);
	substring = fill_sub(substring, (char *) s, (size_t) start, actual_size);
	return (substring);
}
