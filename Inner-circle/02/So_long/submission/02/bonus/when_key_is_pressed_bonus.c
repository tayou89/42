/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   when_key_is_pressed_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 16:01:24 by tayou             #+#    #+#             */
/*   Updated: 2023/05/07 19:26:16 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	define_player_direction_by_key_code(int key_code, t_data *game);
int		action_by_key_code(int key_code, t_data *game);

void	when_key_is_pressed(t_data *game)
{
	mlx_hook(game->window.ptr, KEY_PRESS, 0, &action_by_key_code, game);
}

int	action_by_key_code(int key_code, t_data *game)
{
	if (game->flag.enemy_move == TRUE
		|| game->flag.find_invader == TRUE
		|| game->flag.player_move_complete == FALSE)
		return (0);
	if (key_code == KEY_A || key_code == KEY_D
		|| key_code == KEY_S || key_code == KEY_W)
	{
		game->flag.player_move = TRUE;
		game->flag.player_move_complete = FALSE;
		define_player_direction_by_key_code(key_code, game);
	}
	else if (key_code == KEY_ESC)
		finish_game_after_free(game);
	return (0);
}

void	define_player_direction_by_key_code(int key_code, t_data *game)
{
	if (key_code == KEY_A)
		game->player.direction = LEFT;
	if (key_code == KEY_D)
		game->player.direction = RIGHT;
	if (key_code == KEY_S)
		game->player.direction = DOWN;
	if (key_code == KEY_W)
		game->player.direction = UP;
}
