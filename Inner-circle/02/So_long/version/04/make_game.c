/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 21:52:42 by tayou             #+#    #+#             */
/*   Updated: 2023/04/22 21:16:16 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	decide_block_size(t_data *game);

void	make_game(t_data *game)
{
	game->block_size = 64;
	game->move_count = 0;
	game->collect_count = 0;
	get_mlx_win_ptr(game);
	make_map(game);
	get_player_location(game);
	control_player(game);
	mlx_loop(game->mlx_ptr);
}
