/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 14:35:22 by tayou             #+#    #+#             */
/*   Updated: 2023/01/21 17:44:18 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_string(char *str, int *print_count)
{
	int	str_len;

	if (str == NULL)
		str = "(null)";
	str_len = my_strlen(str);
	write(1, str, str_len);
	(*print_count) += str_len;
}
