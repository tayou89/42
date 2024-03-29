/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 23:01:00 by tayou             #+#    #+#             */
/*   Updated: 2023/04/15 23:09:54 by tayou            ###   ########.fr       */
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

void	free_when_get_new_node_fail(t_node *line)
{
	t_node	*list_head;

	if (line == (void *) 0)
		return ;
	while (line != (void *) 0)
	{
		line_head = line;
		if (line->right != (void *) 0 && line->left == (void *) 0)
			line = line->right;
		else if (line->right == (void *) 0 && line->left != (void *) 0)
			line = line->left;
		else if (line->right == (void *) 0 && line->left == (void *) 0)
			line = line->down;
		free(line_head);
	}
	line = (void *) 0;
}
