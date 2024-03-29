/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_node.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 22:27:17 by tayou             #+#    #+#             */
/*   Updated: 2023/05/03 18:35:54 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_node	*get_new_node(char c)
{
	t_node	*new_node;

	new_node = (t_node *) malloc(sizeof(t_node));
	if (new_node == (void *) 0)
		return ((void *) 0);
	new_node->component = c;
	new_node->accessibility = 'X';
	new_node->check_count = 0;
	new_node->left = (void *) 0;
	new_node->right = (void *) 0;
	new_node->up = (void *) 0;
	new_node->down = (void *) 0;
	new_node->next = (void *) 0;
	return (new_node);
}

t_node	*add_node_right(t_node *line, t_node *new_node)
{
	t_node	*line_head;

	if (line == (void *) 0)
	{
		line = new_node;
		return (line);
	}
	line_head = line;
	while (line->right != (void *) 0)
		line = line->right;
	line->right = new_node;
	new_node->left = line;
	return (line_head);
}

t_node	*link_node_to_next(t_node *list, t_node *node_to_link)
{
	t_node	*list_head;

	if (list == (void *) 0)
	{
		list = node_to_link;
		return (list);
	}
	list_head = list;
	while (list->next != (void *) 0)
		list = list->next;
	list->next = node_to_link;
	return (list_head);
}

t_node	*find_component_node(t_node *map, char c)
{
	t_node	*component_node;
	t_node	*down_line;
	t_node	*left_node;

	while (map != (void *) 0)
	{
		left_node = find_left_node(map);
		down_line = left_node->down;
		while (map != (void *) 0)
		{
			if (map->component == c)
			{
				component_node = map;
				return (component_node);
			}
			else
				map = map->right;
		}
		map = down_line;
	}
	return (map);
}

t_node	*find_left_node(t_node *node)
{
	if (node == (void *) 0)
		return ((void *) 0);
	while (node->left != (void *) 0)
		node = node->left;
	return (node);
}
