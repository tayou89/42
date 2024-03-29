/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 21:52:42 by tayou             #+#    #+#             */
/*   Updated: 2023/04/23 16:43:41 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	make_game(t_data *game)
{
	make_initial_game_setting(game);
	control_player(game);
	mlx_loop(game->mlx_ptr);
}
