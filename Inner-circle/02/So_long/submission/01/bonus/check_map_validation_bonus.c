/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_validation_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 22:30:13 by tayou             #+#    #+#             */
/*   Updated: 2023/05/03 18:49:10 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	check_map_validation(int argc, char **argv, t_data *game)
{
	if (argc != 2)
		exit(0);
	game->map.file_path = argv[1];
	check_map_extension(game);
	get_array_map(game);
	game->map.linked_list = (void *) 0;
	if (check_map_is_rectangular(game) == FALSE
		|| check_map_surrounded_by_wall(game) == FALSE
		|| check_map_component(game) == FALSE
		|| check_map_has_valid_path(game) == FALSE)
	{
		ft_printf("Error\nMap is invalid.\n");
		free_mallocated_data(game);
		exit(2);
	}
}
