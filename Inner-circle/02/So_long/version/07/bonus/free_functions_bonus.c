/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_functions_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 22:31:17 by tayou             #+#    #+#             */
/*   Updated: 2023/05/14 19:10:06 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	free_mallocated_data(t_data *game)
{
	char	**array_map;
	t_node	*linked_list_map;

	array_map = game->map.array;
	linked_list_map = game->map.linked_list;
	if (array_map != (void *) 0)
		free_2d_string_array(array_map);
	if (linked_list_map != (void *) 0)
		free_linked_list(linked_list_map);
	if (game->enemy.map_x != (void *) 0)
	{
		free(game->enemy.map_x);
		free(game->enemy.map_y);
	}
}

void	free_2d_string_array(char **string)
{
	int	i;

	if (string == (void *) 0)
		return ;
	i = 0;
	while (string[i] != (void *) 0)
	{
		free(string[i]);
		i++;
	}
	free(string);
}

void	free_linked_list(t_node *list)
{
	t_node	*list_head;
	t_node	*next_list_head;

	if (list == (void *) 0)
		return ;
	while (list != (void *) 0)
	{
		next_list_head = list->down;
		while (list != (void *) 0)
		{
			list_head = list;
			list = list->right;
			free(list_head);
			list_head = (void *) 0;
		}
		list = next_list_head;
	}
	list = (void *) 0;
}
