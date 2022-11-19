/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 15:22:52 by tayou             #+#    #+#             */
/*   Updated: 2022/11/19 16:07:17 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*changed_s;
	int		i;
	int		s_len;

	if (s[0] == 0)
		return (0);
	s_len = ft_strlen(s);
	changed_s = (char *) malloc(sizeof(char) * s_len + 1);
	if (changed_s == 0)
		return (0);
	i = 0;
	while (s[i] != '\0')
	{
		changed_s[i] = f(i, s[i]);
		i++;
	}
	changed_s[i] = '\0';
	return (changed_s);
}
/*
#include <stdio.h>

char	f(unsigned int i, char c)
{
	i = c;
	if (c >= 'a' && c <= 'z')
		c += 'A' - 'a';
	return (c);
}

int	main()
{
	char	*s = "abcdefg";
	
	printf("s: %s\n", s);
	printf("ft_strmapi: %s\n", ft_strmapi(s, f));
	return (0);
}
*/
