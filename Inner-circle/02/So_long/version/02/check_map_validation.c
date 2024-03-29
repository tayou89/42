/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_validation.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 14:10:20 by tayou             #+#    #+#             */
/*   Updated: 2023/04/15 19:08:41 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_map_validation(int argc, char **argv)
{
	char	**map;

	if (argc != 2)
		exit(0);
	check_map_extension(argv[1]);
	map = get_2d_array_map(argv[1]);
	if (check_map_is_rectangular(map) == 1
		|| check_map_surrounded_by_wall(map) == 1
		|| check_map_component(map) == 1
		|| check_map_has_valid_path(map) == 1)
	{
		ft_printf("Error\nMap is invalid.\n");
		free_2d_string_array(map);
		exit(2);
	}
	free_2d_string_array(map);
}
