/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 21:33:21 by tayou             #+#    #+#             */
/*   Updated: 2022/11/09 22:28:50 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	if (n == 0)
		return (0);
	i = 0;
	while (i < n && s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
		i++;
	if (i == n)
		i--;
	return (s1[i] - s2[i]);
}
/*
#include <stdio.h>
#include <string.h>

int	main()
{
	char	*s1 = "";
	char	*s2 = "abcde";
	size_t	n;

	scanf("%lu", &n);
	printf("strncmp: %d\n", strncmp(s1, s2, n));
	printf("ft_strncmp: %d\n", ft_strncmp(s1, s2, n));
	return (0);
}
*/
