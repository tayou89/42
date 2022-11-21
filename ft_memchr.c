/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 23:52:33 by tayou             #+#    #+#             */
/*   Updated: 2022/11/21 22:16:12 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*copy_s;
	size_t			i;
	size_t			s_len;

	copy_s = (unsigned char *) s;
	s_len = ft_strlen(s);
	if (c == 0)
		return (&copy_s[s_len]);
	i = 0;
	while (*copy_s != '\0' && i < n)
	{
		if (*copy_s == c)
			return ((void *) copy_s);
		else
		{
			copy_s++;
			i++;
		}
	}
	return (NULL);
}
/*
#include <stdio.h>
#include <string.h>

int	main()
{
	char	s[200];
	int		c;
	size_t	n;

	printf("string 입력: ");
	scanf("%s", s);
	printf("숫자 입력: ");
	scanf("%d", &c);
	printf("사이즈 입력: ");
	scanf("%lu", &n);
	printf("memchr: %s\n", memchr(s, c, n));
	printf("ft_memchr: %s\n", ft_memchr(s, c, n));
	return (0);
}
*/
