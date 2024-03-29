/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_initial_game_setting.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 16:05:03 by tayou             #+#    #+#             */
/*   Updated: 2023/04/23 16:44:36 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	get_player_location(t_data *game);

void	make_initial_game_setting(t_data *game)
{
	game->block_size = 64;
	game->move_count = 0;
	game->collect_count = 0;
	get_mlx_win_ptr(game);
	make_map(game);
	get_player_location(game);
	game->array_map[game->player_y][game->player_x] = '0';
}

void	get_player_location(t_data *game)
{
	get_component_location('P', game);
	game->player_x = game->component_x;
	game->player_y = game->component_y;
}
