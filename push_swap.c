/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 15:21:31 by tayou             #+#    #+#             */
/*   Updated: 2023/03/12 08:32:18 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_deque	*get_deque(t_node *stack)
{
	t_deque	*first_last;

	first_last = (t_deque *) malloc(sizeof(t_deque));
	first_last->first = stack;
	while (stack->next != (void *) 0)
		stack = stack->next;
	first_last->last = stack;
	return (first_last);
}

int	*sort_int_array(int *int_array, int int_count)
{
	int	i;
	int	j;
	int	temp;
	
	i = 0;
	while (i + 1 < int_count)
	{
		j = i + 1;
		while (j < int_count)
		{
			if (int_array[i] > int_array[j])
			{
				temp = int_array[i];
				int_array[i] = int_array[j];
				int_array[j] = temp;
			}
			j++;
		}
		i++;
	}
	return (int_array);
}

t_node	*get_original_stack_a(int *int_array, int int_count)
{
	t_node	*stack_a;
	t_node	*new_node;
	int		i;

	stack_a = get_new_node(int_array[0]);
	if (stack_a == (void *) 0)
		return ((void *) 0);
	i = 1;
	while (i < int_count)
	{
		new_node = get_new_node(int_array[i]);
		if (new_node == (void *) 0)
		{
			free_list(stack_a);
			return ((void *) 0);
		}
		stack_a = add_node_back(&stack_a, new_node);
		i++;
	}
	return (stack_a);
}

t_node	*simplify_stack_number(t_node *stack, int *int_array, int int_count)
{
	t_node	*stack_head;
	int		i;

	stack_head = stack;
	i = 0;
	while (i < int_count)
	{
		stack = stack_head;
		while (stack->number != int_array[i])
				stack = stack->next;
		stack->number = i;
		i++;
	}
	return (stack_head);
}

t_node	*get_stack_a(char **argv)
{
	t_node	*stack_a;
	char	**string_array;
	int		*int_array;
	int		int_count;
	int		i;

	string_array = get_string_array(argv);
	int_count = 0;
	int_array = get_int_array(string_array, &int_count);
	stack_a = get_original_stack_a(int_array, int_count);
	if (stack_a == (void *) 0)
	{
		free_array(string_array);
		free(int_array);
		exit(1);
	}
	int_array = sort_int_array(int_array, int_count);
	stack_a = simplify_stack_number(stack_a, int_array, int_count);
	i = 0;
	while (stack_a != (void *) 0)
	{
		ft_printf("stack[%d]->number: %d\n", i, stack_a->number);
		i++;
		stack_a = stack_a->next;
	}
	free_array(string_array);
	free(int_array);
	return (stack_a);
}

int	main(int argc, char *argv[])
{
	t_node	*stack_a;

	check_exception(argc, argv);
	stack_a = get_stack_a(argv);
	
	system("leaks push_swap");
	return (0);
}
