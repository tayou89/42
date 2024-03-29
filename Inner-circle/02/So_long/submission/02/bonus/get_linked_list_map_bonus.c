/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_linked_list_map_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 22:32:15 by tayou             #+#    #+#             */
/*   Updated: 2023/04/23 22:32:23 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

t_node	*get_new_line(char *map_line);
void	link_up_down_line(t_node *up_line, t_node *down_line);

t_node	*get_linked_list_map(char **array_map)
{
	t_node	*up_line;
	t_node	*down_line;
	t_node	*total_line_head;
	int		i;

	up_line = get_new_line(array_map[0]);
	if (up_line == (void *) 0)
		return ((void *) 0);
	total_line_head = up_line;
	i = 1;
	while (array_map[i] != (void *) 0)
	{
		down_line = get_new_line(array_map[i]);
		if (down_line == (void *) 0)
		{
			free_linked_list(total_line_head);
			return ((void *) 0);
		}
		link_up_down_line(up_line, down_line);
		up_line = down_line;
		i++;
	}
	return (total_line_head);
}

t_node	*get_new_line(char *map_line)
{
	t_node	*line;
	t_node	*new_node;
	int		i;

	line = (void *) 0;
	i = 0;
	while (map_line[i] != '\0')
	{
		new_node = get_new_node(map_line[i]);
		if (new_node == (void *) 0)
		{
			free_linked_list(line);
			return ((void *) 0);
		}
		line = add_node_right(line, new_node);
		i++;
	}
	return (line);
}

void	link_up_down_line(t_node *up_line, t_node *down_line)
{
	while (up_line != (void *) 0)
	{
		up_line->down = down_line;
		down_line->up = up_line;
		down_line = down_line->right;
		up_line = up_line->right;
	}
}
