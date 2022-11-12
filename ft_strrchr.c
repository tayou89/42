/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 00:05:06 by tayou             #+#    #+#             */
/*   Updated: 2022/11/08 00:43:53 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *s, int c)
{
	while (*s != '\0')
		s++;
	s--;
	while (*s != (char) c)
	{
		if (*s == '\0')
			return (0);
		s--;
	}
	return ((char *) s);
}
/*
#include <stdio.h>
#include <string.h>

int	main()
{
	char	str[200];
	int		c;
	
	scanf("%s", str);
	scanf("%d", &c);
	printf("str: %s\n", str);
	printf("c: %d\n", c);
	printf("strrchr: %s\n", strrchr(str, c));
	printf("ft_strrchr: %s\n", ft_strrchr(str, c));
	return (0);
}
*/
