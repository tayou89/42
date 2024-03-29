/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 23:26:01 by tayou             #+#    #+#             */
/*   Updated: 2023/05/14 18:44:00 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	count_line_in_string(char *string, int read_size)
{
	int	count;
	int	i;

	if (string == (void *) 0)
		return (0);
	count = 0;
	i = 0;
	while (i < read_size)
	{
		if (string[i] == '\n' || string[i] == '\0')
			count++;
		i++;
	}
	return (count);
}
