/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_enemy_on_guard_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 11:51:10 by tayou             #+#    #+#             */
/*   Updated: 2023/05/06 13:20:22 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	make_enemy_on_guard(t_data *game)
{
	static int	k;

	if (k == 10000)
		turn_enemy_to_direction(game);
	if (k >= 0 && k < 20000)
		check_every_enemy_if_find_invader(&k, game);
	if (k == 20000)
		move_enemy_to_direction(&k, game);
	if (k == 25000)
		finish_game_after_free(game);
	k++;
}
