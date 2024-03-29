/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_until_sorted.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 13:00:35 by tayou             #+#    #+#             */
/*   Updated: 2023/03/21 05:43:20 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_until_sorted(t_node **stack_a, t_node **stack_b)
{
	if (check_perfectly_sorted_stack_a(*stack_a) == 1)
		return ;
	while (check_perfectly_sorted_stack_a(*stack_a) == 0 ||
		   check_perfectly_sorted_stack_b(*stack_b) == 0)
	{
		check_first_second_node(stack_a, stack_b);
		check_if_sorted_stack_b(stack_b, stack_a);
		check_max_number_is_top(stack_b, stack_a);
		check_first_last_node(stack_a, stack_b);
	}
}
