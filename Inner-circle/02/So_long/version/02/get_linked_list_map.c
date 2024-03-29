/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_linked_list_map.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 19:09:13 by tayou             #+#    #+#             */
/*   Updated: 2023/04/15 23:12:55 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_node	*get_linked_list_map(char **2d_array_map)
{
	t_node	*new_line;
	t_node	*up_line;
	t_node	*down_line;
	int		i;

	
	i = 0;
	while (2d_array_map[i] != (void *) 0)
	{
		new_line = get_new_line(2d_array_map[i]);


}

t_node	*get_new_line(char *string, 2d_array_map)
{
	t_node	*line;
	t_node	*new_node;
	int		i;

	line = (void *) 0;
	i = 0;
	while (string[i] != '\0')
	{
		new_node = get_new_node(string[i]);
		if (new_node == (void *) 0)
		{
			free_when_fail_get_new_node(line);
			return ((void *) 0);
		}
		line = add_node_right(line, new_node);
		i++;
	}
	return (line);
}
