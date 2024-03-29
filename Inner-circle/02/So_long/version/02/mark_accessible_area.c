/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mark_accessible_area.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 18:08:01 by tayou             #+#    #+#             */
/*   Updated: 2023/04/15 18:38:58 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	mark_accessible_area(char **marking_map, char **original_map)
{
	int		starting_i;
	int		starting_j;
	char	accessible_sign;

	starting_i = 0;
	starting_j = 0;
	find_starting_point(original_map, &starting_i, &starting_j);
	accessible_sign = 'O';
	mark_accessible_sign_on_starting(marking_map, starting_i, starting_j);

}

void	find_starting_point(char **original_map, int *i, int *j)
{
	while (original_map[*i] != (void *) 0)
	{
		*j = 0;
		while (original_map[*i][*j] != '\0')
		{
			if (original_map[*i][*j] == 'P')
				return ;
			else
				(*j)++;
		}
		(*i)++;
	}
}

void	mark_accessible_sign_on_starting(char **marking_map, int i, int j)
{
	marking_map[i][j] = 'O';
}



