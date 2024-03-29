/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_validation_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 22:30:13 by tayou             #+#    #+#             */
/*   Updated: 2023/04/23 22:30:20 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	check_map_validation(int argc, char **argv, t_data *game)
{
	if (argc != 2)
		exit(0);
	game->map_file_path = argv[1];
	check_map_extension(game);
	game->array_map = get_array_map(game->map_file_path, game);
	if (check_map_is_rectangular(game->array_map) == 1
		|| check_map_surrounded_by_wall(game->array_map) == 1
		|| check_map_component(game->array_map, game) == 1
		|| check_map_has_valid_path(game->array_map, game) == 1)
	{
		ft_printf("Error\nMap is invalid.\n");
		free_mallocated_data(game);
		exit(2);
	}
}
