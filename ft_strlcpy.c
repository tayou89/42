/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 21:35:49 by tayou             #+#    #+#             */
/*   Updated: 2022/11/20 22:30:39 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *restrict dst, const char *restrict src, size_t size)
{
	size_t	i;
	size_t	src_len;

	src_len = ft_strlen(src);
	if (size == 0)
		return (0);
	i = 0;
	while (i < size - 1 && src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (src_len);
}
/*
#include <stdio.h>
#include <string.h>

int	main()
{
	char	dst1[] = "zzzzzzzzzzzz";
	char	dst2[] = "zzzzzzzzzzzz";
	char	*src = "abcdefg";

	printf("dst: %s\n", dst1);
	printf("src: %s\n", src);
	printf("strlcpy return: %lu\n", strlcpy(dst1, src, strlen(dst1)));
	printf("ft_strlcpy return: %lu\n", ft_strlcpy(dst2, src, strlen(dst2)));
	printf("changed strlcpy_dst: %s\n", dst1);
	printf("changed ft_strlcpy_dst: %s\n", dst2);
	return (0);
}
*/
