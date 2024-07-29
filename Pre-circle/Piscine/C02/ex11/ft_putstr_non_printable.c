/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 01:30:32 by tayou             #+#    #+#             */
/*   Updated: 2022/10/12 13:06:34 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr_non_printable(char *str)
{
	int				i;
	unsigned char	*string;
	char			*hexa;
	char			hexa_char[2];

	string = (unsigned char *) str;
	hexa = "0123456789abcdef";
	i = 0;
	while (string[i] != '\0')
	{
		if ((string[i] >= 0 && string[i] <= 31) || string[i] >= 127)
		{	
			write(1, "\\", 1);
			hexa_char[0] = hexa[(string[i] / 16)];
			hexa_char[1] = hexa[(string[i] % 16)];
			write(1, hexa_char, 2);
		}
		else
			write(1, &string[i], 1);
		i++;
	}
}
/*
int	main()
{
	char	str[] = "Coucou\ntu vas bien ?";
	
	ft_putstr_non_printable(str);
	return 0;
}
*/
