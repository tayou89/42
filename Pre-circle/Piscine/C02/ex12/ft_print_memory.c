/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 21:36:44 by tayou             #+#    #+#             */
/*   Updated: 2022/10/12 03:32:20 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_str(unsigned char *str, int unsigned size)
{
	unsigned int	i;

	i = 0;
	while (i < size)
	{
		if (str[i] >= 32 && str[i] <= 126)
			write(1, &str[i], 1);
		else
			write(1, ".", 1);
		i++;
	}
}

void	print_str_hex(unsigned char *str, int unsigned size)
{
	char			*hexa;
	char			hexa_char[2];
	unsigned int	i;
	unsigned int	remainder;

	hexa = "0123456789abcdef";
	i = 0;
	while (i < 16)
	{
		if (i < size)
		{
			hexa_char[0] = hexa[(str[i] / 16)];
			hexa_char[1] = hexa[(str[i] % 16)];
			write(1, hexa_char, 2);
		}	
		else
			write(1, "  ", 2);
		remainder = i % 2;
		if (remainder == 1)
			write(1, " ", 1);
		i++;
	}
}

void	print_address_hexa(unsigned char *str)
{
	char		*hexa;
	char		hexa_address[16];
	char		hexa_char;
	long long	address;
	int			i;

	hexa = "0123456789abcdef";
	address = (long long)str;
	i = 15;
	while (i >= 0)
	{
		hexa_char = hexa[(address % 16)];
		hexa_address[i] = hexa_char;
		address /= 16;
		i--;
	}
	write(1, hexa_address, 16);
	write(1, ": ", 2);
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned char	*str;
	unsigned int	i;

	str = (unsigned char *) addr;
	i = 0;
	while (i < (size / 16))
	{
		print_address_hexa(str);
		print_str_hex(str, 16);
		print_str(str, 16);
		write(1, "\n", 1);
		str += 16;
		i++;
	}
	if ((size % 16) > 0)
	{
		print_address_hexa(str);
		print_str_hex(str, size % 16);
		print_str(str, size % 16);
	}
	write(1, "\n", 1);
	return (addr);
}
