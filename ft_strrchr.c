/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 00:05:06 by tayou             #+#    #+#             */
/*   Updated: 2023/01/07 14:30:18 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	copy_c;
	int		size;
	int		i;

	copy_c = (char) c;
	size = ft_strlen(s);
	i = size;
	while (i >= 0)
	{
		if (s[i] != copy_c)
			i--;
		else
			break ;
	}
	if (i < 0)
		return (0);
	return ((char *) &s[i]);
}
