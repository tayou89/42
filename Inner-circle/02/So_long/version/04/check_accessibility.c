/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_accessibility.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 23:05:19 by tayou             #+#    #+#             */
/*   Updated: 2023/04/16 23:07:34 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_node	*get_accessible_node(t_node *accessible_node);
int		check_node_accessible(t_node *node);

t_node	*check_accessibility(t_node *map)
{
	t_node	*p_node;
	t_node	*accessible_node;

	p_node = find_component_node(map, 'P');
	p_node->accessibility = 'O';
	accessible_node = p_node;
	while (accessible_node != (void *) 0)
	{
		accessible_node = get_accessible_node(accessible_node);
		accessible_node->check_count = 1;
		accessible_node = accessible_node->next;
	}
	return (map);
}

t_node	*get_accessible_node(t_node *accessible_node)
{
	t_node	*accessible_node_head;
	t_node	*check_node;

	accessible_node_head = accessible_node;
	check_node = accessible_node->up;
	if (check_node_accessible(check_node) == 1)
		accessible_node = link_node_to_next(accessible_node, check_node);
	check_node = accessible_node->right;
	if (check_node_accessible(check_node) == 1)
		accessible_node = link_node_to_next(accessible_node, check_node);
	check_node = accessible_node->down;
	if (check_node_accessible(check_node) == 1)
		accessible_node = link_node_to_next(accessible_node, check_node);
	check_node = accessible_node->left;
	if (check_node_accessible(check_node) == 1)
		accessible_node = link_node_to_next(accessible_node, check_node);
	return (accessible_node_head);
}

int	check_node_accessible(t_node *node)
{
	if (node->check_count == 0 && node->accessibility == 'X'
		&& (node->component == '0' || node->component == 'C'))
	{
		node->accessibility = 'O';
		return (1);
	}
	else
		return (0);
}
