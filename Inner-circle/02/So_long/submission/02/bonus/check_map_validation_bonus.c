/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_validation_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 22:30:13 by tayou             #+#    #+#             */
/*   Updated: 2023/05/08 11:51:58 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	print_error_message(t_data *game);

void	check_map_validation(int argc, char **argv, t_data *game)
{
	if (argc != 2)
	{
		ft_printf("Error.\nWrong Argument.\n");
		exit(0);
	}
	game->map.file_path = argv[1];
	check_map_extension(game);
	get_array_map(game);
	game->map.linked_list = (void *) 0;
	if (check_map_is_rectangular(game) == FALSE
		|| check_map_surrounded_by_wall(game) == FALSE
		|| check_map_component(game) == FALSE
		|| check_map_has_valid_path(game) == FALSE)
	{
		print_error_message(game);
		free_mallocated_data(game);
		exit(2);
	}
}

void	print_error_message(t_data *game)
{
	ft_printf("Error\n");
	ft_printf("Map is invalid.\n");
	if (game->error_number == 1)
		ft_printf("Map is not rectangular.\n");
	else if (game->error_number == 2)
		ft_printf("Map is not surrounded by wall.\n");
	else if (game->error_number == 3)
		ft_printf("Map has problem of component.\n");
	else if (game->error_number == 4)
		ft_printf("Map does not have valid path.\n");
}
