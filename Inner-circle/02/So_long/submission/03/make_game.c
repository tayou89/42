/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 21:52:42 by tayou             #+#    #+#             */
/*   Updated: 2023/05/03 15:36:09 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	make_game(t_data *game)
{
	make_initial_game_setting(game);
	when_key_is_pressed(game);
	when_click_x_button_on_window(game);
	mlx_loop(game->mlx.ptr);
}
