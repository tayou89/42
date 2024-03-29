/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_node.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 22:27:17 by tayou             #+#    #+#             */
/*   Updated: 2023/04/15 23:00:22 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_node	*get_new_node(char c)
{
	t_node *new_node;

	new_node = (t_node *) malloc(sizeof(t_node));
	if (new_node == (void *) 0)
		return ((void *) 0);
	new_node->component = c;
	new_node->visit_count = 0;
	new_node->left = (void *) 0;
	new_node->right = (void *) 0;
	new_node->up = (void *) 0;
	new_node->down = (void *) 0;
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
