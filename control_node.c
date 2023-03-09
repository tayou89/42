/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_node.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 11:43:09 by tayou             #+#    #+#             */
/*   Updated: 2023/03/09 11:44:50 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*find_node_last(t_node *stack)
{
	if (stack == (void *) 0)
		return (stack);
	while (stack->next != (void *) 0)
		stack = stack->next;
	return (stack);
}

t_node	*get_new_node(int number)
{
	t_node	*new_node;

	new_node = (t_node *) malloc(sizeof(t_node));
	if (new_node == 0)
		return (0);
	new_node->number = number;
	new_node->prev = (void *) 0;
	new_node->next = (void *) 0;
	return (new_node);
}

t_node	*add_node_back(t_node **stack, t_node *new_node)
{
	t_node	*copy_head;

	if (stack == (void *) 0)
	{
		*stack = new_node;
		return (*stack);
	}
	copy_head = *stack;
	while (copy_head->next != (void *) 0)
		copy_head = copy_head->next;
	copy_head->next = new_node;
	new_node->prev = copy_head;
	return (*stack);
}

t_node	*add_node_front(t_node **stack, t_node *new_node)
{
	if (new_node == (void *) 0)
		return (*stack);
	if (stack == (void *) 0)
	{
		*stack = new_node;
		return (*stack);
	}
	new_node->next = *stack;
	*stack = new_node;
	return (*stack);
}

t_node	*del_node_front(t_node *stack)
{
	t_node	*temp;

	temp = stack;
	if (stack->next != (void *) 0)
		stack->next->prev = (void *) 0;
	stack = stack->next;
	free(temp);
	temp = (void *) 0;
	return (stack);
}
