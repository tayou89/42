/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 20:56:29 by tayou             #+#    #+#             */
/*   Updated: 2022/11/17 23:24:33 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	get_len(char *start_address, char *end_address)
{
	size_t	trimmed_len;

	trimmed_len = 0;
	while (start_address <= end_address)
	{
		start_address++;
		trimmed_len++;
	}
	return (trimmed_len);
}

char	*get_trimmed(char const *s1, char const *set, size_t s1_l, size_t set_l)
{
	char	*start_address;
	char	*end_address;
	char	*trimmed_string;
	size_t	trimmed_len;

	if (ft_strnstr(s1, set, s1_l) == 0)
		return (ft_strdup(s1));
	start_address = ft_strnstr(s1, set, s1_l) + set_l;
	if (ft_strnstr(start_address, set, s1_l) == 0)
		return (0);
	end_address = ft_strnstr(start_address, set, s1_l) - 1;
	trimmed_len = get_len(start_address, end_address);
	trimmed_string = (char *) malloc(sizeof(char) * trimmed_len + 1);
	if (trimmed_string == 0)
		return (0);
	while (start_address <= end_address)
	{
		*trimmed_string = *start_address;
		trimmed_string++;
		start_address++;
	}
	*trimmed_string = '\0';
	return (trimmed_string - trimmed_len);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*trimmed_s1;
	int		s1_len;
	int		set_len;

	s1_len = (int) ft_strlen(s1);
	set_len = (int) ft_strlen(set);
	if (s1_len == 0)
		return (0);
	if (set_len == 0)
		return (ft_strdup(s1));
	trimmed_s1 = get_trimmed(s1, set, s1_len, set_len);
	return (trimmed_s1);
}
#include <stdio.h>

int	main()
{
	char	*s1 = "The boy is good";
	char	*set = "";

	printf("s1: %s\n", s1);
	printf("set: %s\n", set);
	printf("trimmed_s1: %s\n", ft_strtrim(s1, set));
	return (0);
}
