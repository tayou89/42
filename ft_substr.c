/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 20:15:09 by tayou             #+#    #+#             */
/*   Updated: 2022/11/21 22:06:56 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substring;
	size_t	i;
	size_t	s_len;

	substring = (char *) malloc(sizeof(char) * len + 1);
	if (substring == 0)
		return (0);
	s_len = ft_strlen(s);
	if (start >= s_len)
	{
		substring[0] = '\0';
		return (substring);
	}
	i = 0;
	while (i < len && s[start] != '\0')
	{
		substring[i] = s[start];
		i++;
		start++;
	}
	substring[i] = '\0';
	return (substring);
}
/*
#include <stdio.h>

int	main()
{
	char			*s = "abcdefg";
	unsigned int	start;
	size_t			len;

	printf("s: %s\n", s);
	printf("start: ");
	scanf("%u", &start);
	printf("len: ");
	scanf("%lu", &len);
	printf("substring: %s\n", ft_substr(s, start, len));
	return (0);
}
*/
