/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_component_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 22:28:54 by tayou             #+#    #+#             */
/*   Updated: 2023/04/23 22:29:09 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	check_if_has_other_character(char **map);
int	get_exit_count(char **map);
int	get_collectible_count(char **map);
int	get_player_count(char **map);

int	check_map_component(char **map, t_data *game)
{
	if (check_if_has_other_character(map) == 1)
		return (1);
	game->exit_count = get_exit_count(map);
	game->collectible_count = get_collectible_count(map);
	game->player_count = get_player_count(map);
	if (game->exit_count != 1 || game->collectible_count < 1
		|| game->player_count != 1)
		return (1);
	else
		return (0);
}

int	get_exit_count(char **map)
{
	int		exit_count;
	char	exit_character;
	int		i;
	int		j;

	exit_count = 0;
	exit_character = 'E';
	i = 0;
	while (map[i] != (void *) 0)
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if (map[i][j] == exit_character)
				exit_count++;
			j++;
		}
		i++;
	}
	return (exit_count);
}

int	get_collectible_count(char **map)
{
	int		collectible_count;
	char	collectible_character;
	int		i;
	int		j;

	collectible_count = 0;
	collectible_character = 'C';
	i = 0;
	while (map[i] != (void *) 0)
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if (map[i][j] == collectible_character)
				collectible_count++;
			j++;
		}
		i++;
	}
	return (collectible_count);
}

int	get_player_count(char **map)
{
	int		player_count;
	char	player_character;
	int		i;
	int		j;

	player_count = 0;
	player_character = 'P';
	i = 0;
	while (map[i] != (void *) 0)
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if (map[i][j] == player_character)
				player_count++;
			j++;
		}
		i++;
	}
	return (player_count);
}

int	check_if_has_other_character(char **map)
{
	int	i;
	int	j;
	
	i = 0;
	while (map[i] != (void *) 0)
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if (map[i][j] == '0' || map[i][j] == '1' || map[i][j] == 'C'
				|| map[i][j] == 'E' || map[i][j] == 'P')
				j++;
			else
				return (1);
		}
		i++;
	}
	return (0);
}
