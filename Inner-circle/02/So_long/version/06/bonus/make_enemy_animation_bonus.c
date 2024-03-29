/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_enemy_animation_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 12:48:36 by tayou             #+#    #+#             */
/*   Updated: 2023/04/28 14:15:27 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	make_turn_to_direction(int *enemy_x, int *enemy_y, t_data *game);
void	make_turn_to_clockwise(int x, int y, int dir, t_data *game);
int		check_invader_on_sight(int *enemy_x, int *enemy_y, t_data *game);
void	move_enemy_to_player(int *enemy_x, int *enemy_y, t_data *game);
int		check_raider_on_sight(int x, int y, int dir, t_data *game);
void	move_to_player(int *x, int *y, int dir, t_data *game);
void	move_one_block_to_direction(int x, int y, int dir, t_data *game);
void	move_to_target(int enemy_x, int enemy_y, int dir, t_data *game);
void	count_xy_by_direction(int *x, int *y, int dir);
void	get_target_location(int x, int y, int dir, t_data *game);
void	apply_block_size_to_xy(int *x, int *y, int block_size);

int	make_enemy_on_guard(t_data *game)
{
	static int	k;
	int	on_sight_sign;

	ft_printf("k: %d\n", k);
	if (k == 10000)
	{
		if (game->enemy_direction == 3)
			game->enemy_direction = 0;
		else
			game->enemy_direction++;
		make_turn_to_direction(game->enemy_x, game->enemy_y, game);
	}
	if (k == 20000)
	{
		on_sight_sign = check_invader_on_sight(game->enemy_x, game->enemy_y, game);
		if (on_sight_sign == 0)
		{
			k = 0;
			return (0);
		}
	}
	if (k == 30000)
		move_enemy_to_player(game->enemy_x, game->enemy_y, game);
	if (k == 40000)
		finish_game_after_free(game);
	k++;
	return (0);
}

	
void	make_turn_to_direction(int *enemy_x, int *enemy_y, t_data *game)
{
	int			dir;
//	int			on_sight_sign;
	int			i;
	
	dir = game->enemy_direction;
	i = 0;
	while (i < game->enemy_count)
	{
		make_turn_to_clockwise(enemy_x[i], enemy_y[i], dir, game);
		i++;
	}
}

void	make_turn_to_clockwise(int enemy_x, int enemy_y, int dir, t_data *game)
{
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->empty, \
			enemy_x * game->block_size, enemy_y * game->block_size);
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, \
			game->enemy[dir][0].image, \
			enemy_x * game->block_size, enemy_y * game->block_size);
}

int	check_invader_on_sight(int *enemy_x, int *enemy_y, t_data *game)
{
	int			dir;
	int			on_sight_sign;
	int			i;
	
	dir = game->enemy_direction;
	i = 0;
	while (i < game->enemy_count)
	{
		ft_printf("i: %d\n", i);
		on_sight_sign = check_raider_on_sight(enemy_x[i], enemy_y[i], dir, game);
		ft_printf("on_sight_sign: %d\n", on_sight_sign);
		if (on_sight_sign == 1)
		{
			game->witness = i;
			return (on_sight_sign);
		}
		i++;
	}
	return (0);
}

int	check_raider_on_sight(int enemy_x, int enemy_y, int dir, t_data *game)
{
	char	**map;

	map = game->array_map;
	while (map[enemy_y][enemy_x] == '0' || map[enemy_y][enemy_x] == 'B'
			|| map[enemy_y][enemy_x] == 'C')
	{
		ft_printf("enemy_x: %d, enemy_y: %d\n", enemy_x, enemy_y);
		ft_printf("player_x: %d, player_y: %d\n", game->player_x, game->player_y);
		if (enemy_x == game->player_x && enemy_y == game->player_y)
			return (1);
		ft_printf("dir: %d\n", dir);
		count_xy_by_direction(&enemy_x, &enemy_y, dir);
	}
	return (0);
}

void	move_enemy_to_player(int *enemy_x, int *enemy_y, t_data *game)
{
	int	dir;
	int	witness;
	
	dir = game->enemy_direction;
	witness = game->witness;
	while (enemy_x[witness] != game->player_x || enemy_y[witness] != game->player_y)
		move_to_player(&enemy_x[witness], &enemy_y[witness], dir, game);
}

void	move_to_player(int *enemy_x, int *enemy_y, int dir, t_data *game)
{
	if (*enemy_x != game->player_x || *enemy_y != game->player_y)
	{
		move_one_block_to_direction(*enemy_x, *enemy_y, dir, game);
		count_xy_by_direction(enemy_x, enemy_y, dir);
	}
}

void	move_one_block_to_direction(int enemy_x, int enemy_y, \
		int dir, t_data *game)
{
	get_target_location(enemy_x, enemy_y, dir, game);
	apply_block_size_to_xy(&enemy_x, &enemy_y, game->block_size);
	apply_block_size_to_xy(&game->enemy_target_x, &game->enemy_target_y, \
			game->block_size);
	move_to_target(enemy_x, enemy_y, dir, game);
}

void	get_target_location(int enemy_x, int enemy_y, \
		int direction, t_data *game)
{
	count_xy_by_direction(&enemy_x, &enemy_y, direction);
	game->enemy_target_x = enemy_x;
	game->enemy_target_y = enemy_y;
}

void	move_to_target(int enemy_x, int enemy_y, int dir, t_data *game)
{
	int	initial_x;
	int	initial_y;
	int	image_number;
	int	i;

	initial_x = enemy_x;
	initial_y = enemy_y;
	image_number = 0;
	i = 1;
	while (i <= game->block_size)
	{
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->empty, 
				initial_x, initial_y);
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->empty, 
				game->enemy_target_x, game->enemy_target_y);
		if (image_number == 3)
			image_number = 0;
		else
			image_number++;
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, \
			game->enemy[dir][image_number].image, enemy_x, enemy_y);
		count_xy_by_direction(&enemy_x, &enemy_y, dir);
		i++;
	}
}

void	count_xy_by_direction(int *x, int *y, int dir)
{
	if (dir == LEFT)
		(*x)--;
	else if (dir == RIGHT)
		(*x)++;
	else if (dir == DOWN)
		(*y)++;
	else if (dir == UP)
		(*y)--;
}

void	apply_block_size_to_xy(int *x, int *y, int block_size)
{
	*x = (*x) * block_size;
	*y = (*y) * block_size;
}
