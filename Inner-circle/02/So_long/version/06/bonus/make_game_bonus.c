/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_game_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 22:32:41 by tayou             #+#    #+#             */
/*   Updated: 2023/04/28 13:56:28 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	make_game(t_data *game)
{
	make_initial_game_setting(game);
	control_player(game);
	mlx_loop_hook(game->mlx_ptr, &make_enemy_on_guard, game);
	mlx_loop(game->mlx_ptr);
}
