/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   when_key_is_pressed.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 13:01:44 by tayou             #+#    #+#             */
/*   Updated: 2023/05/07 19:26:29 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	define_player_direction_by_key_code(int key_code, t_data *game);
int		action_by_key_code(int key_code, t_data *game);
void	get_target_xy_by_direction(t_data *game);
void	check_movible_by_target_component(t_data *game);

void	when_key_is_pressed(t_data *game)
{
	mlx_hook(game->window.ptr, KEY_PRESS, 0, &action_by_key_code, game);
}

int	action_by_key_code(int key_code, t_data *game)
{
	if (key_code == KEY_A || key_code == KEY_D
		|| key_code == KEY_S || key_code == KEY_W)
	{
		define_player_direction_by_key_code(key_code, game);
		get_target_xy_by_direction(game);
		check_movible_by_target_component(game);
		if (game->flag.movible == TRUE)
			make_player_move_to_target(game);
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

void	get_target_xy_by_direction(t_data *game)
{
	game->player.target_x = game->player.map_x;
	game->player.target_y = game->player.map_y;
	if (game->player.direction == LEFT)
		game->player.target_x--;
	else if (game->player.direction == RIGHT)
		game->player.target_x++;
	else if (game->player.direction == DOWN)
		game->player.target_y++;
	else if (game->player.direction == UP)
		game->player.target_y--;
}

void	check_movible_by_target_component(t_data *game)
{
	game->component.target \
		= game->map.array[game->player.target_y][game->player.target_x];
	if (game->component.target == game->component.collectible
		|| game->component.target == game->component.empty_space)
		game->flag.movible = TRUE;
	else if (game->component.target == game->component.wall)
		game->flag.movible = FALSE;
	else if (game->component.target == game->component.exit)
	{
		if (game->count.collect == game->count.collectible)
		{
			finish_game_after_free(game);
			exit(0);
		}
		else
			game->flag.movible = FALSE;
	}
}
