/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_image_address_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 12:24:15 by tayou             #+#    #+#             */
/*   Updated: 2023/05/07 14:05:20 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	get_player_image(t_data *game);
void	get_enemy_image(t_data *game);
void	*get_xpm(char *file_path, t_data *game);

void	get_image_address(t_data *game)
{
	game->image.empty = get_xpm("./textures/empty.xpm", game);
	game->image.wall = get_xpm("./textures/wall.xpm", game);
	game->image.collectible = get_xpm("./textures/coll.xpm", game);
	game->image.exit = get_xpm("./textures/exit.xpm", game);
	game->image.done = get_xpm("./textures/done.xpm", game);
	game->image.square_button = get_xpm("./textures/square_button.xpm", game);
	get_player_image(game);
	get_enemy_image(game);
}

void	get_player_image(t_data *game)
{
	game->image.player[LEFT][0] = get_xpm("./textures/p_left1.xpm", game);
	game->image.player[LEFT][1] = get_xpm("./textures/p_left2.xpm", game);
	game->image.player[LEFT][2] = get_xpm("./textures/p_left1.xpm", game);
	game->image.player[LEFT][3] = get_xpm("./textures/p_left3.xpm", game);
	game->image.player[RIGHT][0] = get_xpm("./textures/p_right1.xpm", game);
	game->image.player[RIGHT][1] = get_xpm("./textures/p_right2.xpm", game);
	game->image.player[RIGHT][2] = get_xpm("./textures/p_right1.xpm", game);
	game->image.player[RIGHT][3] = get_xpm("./textures/p_right3.xpm", game);
	game->image.player[DOWN][0] = get_xpm("./textures/p_down1.xpm", game);
	game->image.player[DOWN][1] = get_xpm("./textures/p_down2.xpm", game);
	game->image.player[DOWN][2] = get_xpm("./textures/p_down1.xpm", game);
	game->image.player[DOWN][3] = get_xpm("./textures/p_down3.xpm", game);
	game->image.player[UP][0] = get_xpm("./textures/p_up1.xpm", game);
	game->image.player[UP][1] = get_xpm("./textures/p_up2.xpm", game);
	game->image.player[UP][2] = get_xpm("./textures/p_up1.xpm", game);
	game->image.player[UP][3] = get_xpm("./textures/p_up3.xpm", game);
}

void	get_enemy_image(t_data *game)
{
	game->image.enemy[LEFT][0] = get_xpm("./textures/e_left1.xpm", game);
	game->image.enemy[LEFT][1] = get_xpm("./textures/e_left2.xpm", game);
	game->image.enemy[LEFT][2] = get_xpm("./textures/e_left1.xpm", game);
	game->image.enemy[LEFT][3] = get_xpm("./textures/e_left3.xpm", game);
	game->image.enemy[RIGHT][0] = get_xpm("./textures/e_right1.xpm", game);
	game->image.enemy[RIGHT][1] = get_xpm("./textures/e_right2.xpm", game);
	game->image.enemy[RIGHT][2] = get_xpm("./textures/e_right1.xpm", game);
	game->image.enemy[RIGHT][3] = get_xpm("./textures/e_right3.xpm", game);
	game->image.enemy[DOWN][0] = get_xpm("./textures/e_down1.xpm", game);
	game->image.enemy[DOWN][1] = get_xpm("./textures/e_down2.xpm", game);
	game->image.enemy[DOWN][2] = get_xpm("./textures/e_down1.xpm", game);
	game->image.enemy[DOWN][3] = get_xpm("./textures/e_down3.xpm", game);
	game->image.enemy[UP][0] = get_xpm("./textures/e_up1.xpm", game);
	game->image.enemy[UP][1] = get_xpm("./textures/e_up2.xpm", game);
	game->image.enemy[UP][2] = get_xpm("./textures/e_up1.xpm", game);
	game->image.enemy[UP][3] = get_xpm("./textures/e_up3.xpm", game);
}

void	*get_xpm(char *file_path, t_data *game)
{
	void	*image;

	image = mlx_xpm_file_to_image(game->mlx.ptr, file_path, \
			&game->window.block_size, &game->window.block_size);
	return (image);
}
