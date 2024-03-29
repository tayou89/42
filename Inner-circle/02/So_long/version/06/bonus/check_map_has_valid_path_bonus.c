/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_has_valid_path_bonus.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 22:29:29 by tayou             #+#    #+#             */
/*   Updated: 2023/04/26 12:11:26 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	check_c_and_e_are_accessible(t_node *map);
int	check_accessible(t_node *check_node);
int	get_accessible_count(t_node *check_node);

int	check_map_has_valid_path(char **map, t_data *game)
{
	t_node	*linked_list_map;

	linked_list_map = get_linked_list_map(map);
	if (linked_list_map == (void *) 0)
	{
		free_2d_string_array(map);
		exit(1);
	}
	linked_list_map = check_accessibility(linked_list_map);
	game->linked_list_map = linked_list_map;
	if (check_c_and_e_are_accessible(linked_list_map) == 1)
		return (1);
	return (0);
}

int	check_c_and_e_are_accessible(t_node *map)
{
	t_node	*down_line;

	while (map != (void *) 0)
	{
		down_line = map->down;
		while(map != (void *) 0)
		{
			if (map->component == 'C' || map->component == 'E')
			{
				if (check_accessible(map) == 1)
					return (1);
			}
			map = map->right;
		}
		map = down_line;
	}
	return (0);
}

int	check_accessible(t_node *check_node)
{
	int	accessible_count;

	if (check_node->component == 'C')
	{
		if (check_node->accessibility == 'X')
			return (1);
	}
	if (check_node->component == 'E')
	{
		accessible_count = get_accessible_count(check_node);
		if (accessible_count == 0)
			return (1);
	}
	return (0);
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
