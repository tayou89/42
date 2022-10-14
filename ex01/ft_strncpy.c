/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 01:32:47 by tayou             #+#    #+#             */
/*   Updated: 2022/10/14 19:21:40 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (i < n && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}
/*
#include <unistd.h>
#include <stdio.h>
#include <string.h>

int	main()
{
	char	dest1[250] = "FFFFFFFFFFFFFFFFFFFF";
	char	dest2[250] = "FFFFFFFFFFFFFFFFFFFF";
	char	src[] = "";

	printf("dest : %s\n", dest1);
	printf("src : %s\n", src);
	ft_strncpy(dest1, src, 15);
	printf("changed dest : %s\n", dest1);
	strncpy(dest2, src, 15);
	printf("charged dest : %s\n", dest2);

	return 0;
}
*/
