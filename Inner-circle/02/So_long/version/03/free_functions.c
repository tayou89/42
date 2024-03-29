/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 23:01:00 by tayou             #+#    #+#             */
/*   Updated: 2023/04/16 16:25:32 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_2d_string_array(char **string)
{
	int	i;

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
