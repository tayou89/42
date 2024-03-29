/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_linked_list_map.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 22:53:52 by tayou             #+#    #+#             */
/*   Updated: 2023/04/16 22:58:05 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_linked_list_map(t_node *map)
{
	t_node	*left_node;

	while (map != (void *) 0)
	{
		left_node = map;
		while (map != (void *) 0)
		{
			ft_printf("%c", map->accessibility);
			map = map->right;
		}
		ft_printf("\n");
		map = left_node->down;
	}
}
