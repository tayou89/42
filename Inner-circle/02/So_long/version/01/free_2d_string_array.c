/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_2d_string_array.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 10:35:06 by tayou             #+#    #+#             */
/*   Updated: 2023/04/12 10:35:57 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_2d_string_array(char **string)
{
	int	i;

	i = 0;
	while (string[i] != (void *) 0)
	{
		free(string[i]);
		i++;
	}
	free(string);
}
