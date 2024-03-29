/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_has_valid_path_bonus.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 22:29:29 by tayou             #+#    #+#             */
/*   Updated: 2023/05/03 18:37:56 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	check_c_and_e_are_accessible(t_node *map);
int	check_accessible(t_node *check_node);
int	get_accessible_count(t_node *check_node);

int	check_map_has_valid_path(t_data *game)
{
	char	**map;

	map = game->map.array;
	game->map.linked_list = get_linked_list_map(map);
	if (game->map.linked_list == (void *) 0)
	{
		free_2d_string_array(map);
		exit(1);
	}
	game->map.linked_list = check_accessibility(game->map.linked_list);
	if (check_c_and_e_are_accessible(game->map.linked_list) == FALSE)
		return (FALSE);
	return (TRUE);
}

int	check_c_and_e_are_accessible(t_node *map)
{
	t_node	*down_line;

	while (map != (void *) 0)
	{
		down_line = map->down;
		while (map != (void *) 0)
		{
			if (map->component == 'C' || map->component == 'E')
			{
				if (check_accessible(map) == FALSE)
					return (FALSE);
			}
			map = map->right;
		}
		map = down_line;
	}
	return (TRUE);
}

int	check_accessible(t_node *check_node)
{
	int	accessible_count;

	if (check_node->component == 'C')
	{
		if (check_node->accessibility == 'X')
			return (FALSE);
	}
	if (check_node->component == 'E')
	{
		accessible_count = get_accessible_count(check_node);
		if (accessible_count == 0)
			return (FALSE);
	}
	return (TRUE);
}

int	get_accessible_count(t_node *check_node)
{
	int	accessible_count;

	accessible_count = 0;
	if (check_node->up->accessibility == 'O')
		accessible_count++;
	if (check_node->right->accessibility == 'O')
		accessible_count++;
	if (check_node->down->accessibility == 'O')
		accessible_count++;
	if (check_node->left->accessibility == 'O')
		accessible_count++;
	return (accessible_count);
}
