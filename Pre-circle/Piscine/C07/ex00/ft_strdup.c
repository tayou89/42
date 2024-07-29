/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 14:28:07 by tayou             #+#    #+#             */
/*   Updated: 2022/10/19 20:00:06 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(char *src)
{
	int		i;
	int		src_size;
	char	*copy_src;

	i = 0;
	while (src[i] != '\0')
		i++;
	src_size = i;
	copy_src = (char *) malloc((sizeof(char) * src_size) + 1);
	if (copy_src == 0)
		return (0);
	i = 0;
	while (src[i] != '\0')
	{
		copy_src[i] = src[i];
		i++;
	}
	copy_src[i] = '\0';
	return (copy_src);
}
/*
#include <stdio.h>

int	main()
{
	char	src[] = "";

	printf("src : %s\n", src);
	printf("copy_src: %s\n", ft_strup(src));
	return (0);
}
*/
