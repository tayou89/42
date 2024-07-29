/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 07:44:24 by tayou             #+#    #+#             */
/*   Updated: 2022/10/14 21:31:42 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	get_size(char *array)
{
	unsigned int	i;

	i = 0;
	while (array[i] != '\0')
		i++;
	return (i);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	src_size;
	unsigned int	dest_size;

	src_size = get_size(src);
	dest_size = get_size(dest);
	if (size < dest_size)
		return (src_size + size);
	i = dest_size;
	j = 0;
	while (i + 1 < size && src[j])
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (src_size + dest_size);
}
/*
#include <stdio.h>
#include <string.h>

int	main()
{
	char			dest1[30] = "po";
	char			dest2[30] = "po";
	char			src[30] = "pouic";
	unsigned int	n;

	n = 1;

	printf("strlcat return : %lu\n", strlcat(dest1, src, n));
	printf("ft_strlcat return : %u\n", ft_strlcat(dest2, src, n));
	printf("strlcat dest : %s\n", dest1);
	printf("ft_strlcat dest : %s\n", dest2);

	return 0;
}
*/
