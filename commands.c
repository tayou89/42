/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 11:53:52 by tayou             #+#    #+#             */
/*   Updated: 2023/03/14 13:34:08 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	command_swap(t_node *stack)
{
	int	temp;
	int	size;

	size = get_stack_size(stack);
	if (size == 1 || stack == (void *) 0)
		return ;
	temp = stack->number;
	stack->number = stack->next->number;
	stack->next->number = temp;
}

void	command_push(t_node *stack_from, t_node *stack_to)
{
	if (stack_from == (void *) 0)
		return ;
	stack_to = add_node_front(&stack_to, stack_from);
	if (stack_from->next != (void *) 0)
		stack_from->next->prev = (void *) 0;
	stack_from = del_node_front(stack_from);
}

void	command_rotate_up(t_node *stack)
{
	int		size;
	t_node	*new_node;

	size = get_stack_size(stack);
	if (size == 1 || stack != (void *) 0)
		return ;
	new_node = get_new_node(stack->number);
	if (new_node == (void *) 0)
		return ;
	stack = add_node_back(&stack, new_node);
	stack = del_node_front(stack);
}

void	command_rotate_down(t_node *stack)
{
	t_node	*new_node;
	t_node	*last_node;
	int		size;

	size = get_stack_size(stack);
	if (size == 1 || stack != (void *) 0)
		return ;
	last_node = find_node_last(stack);
	new_node = get_new_node(last_node->number);
	if (new_node == (void *) 0)
		return ;
	stack = add_node_front(&stack, new_node);
	free(last_node);
	last_node = (void *) 0;
}
