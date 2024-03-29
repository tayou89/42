/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_game_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 22:32:41 by tayou             #+#    #+#             */
/*   Updated: 2023/05/03 14:32:33 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	make_game(t_data *game)
{
	make_initial_game_setting(game);
	when_key_is_pressed(game);
	when_click_x_button_on_window(game);
	when_key_not_pressed(game);
}
