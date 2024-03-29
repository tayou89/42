/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_component.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 15:14:04 by tayou             #+#    #+#             */
/*   Updated: 2023/04/14 16:01:50 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_if_has_other_character(char **map);
int	get_exit_count(char **map);
int	get_collectible_count(char **map);
int	get_starting_count(char **map);

int	check_map_component(char **map)
{
	int	exit_count;
	int	collectible_count;
	int	starting_count;

	if (check_if_has_other_character(map) == 1)
		return (1);
	exit_count = get_exit_count(map);
	collectible_count = get_collectible_count(map);
	starting_count = get_starting_count(map);
	if (exit_count != 1 || collectible_count < 1 || starting_count != 1)
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

int	get_starting_count(char **map)
{
	int		starting_count;
	char	starting_character;
	int		i;
	int		j;

	starting_count = 0;
	starting_character = 'P';
	i = 0;
	while (map[i] != (void *) 0)
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if (map[i][j] == starting_character)
				starting_count++;
			j++;
		}
		i++;
	}
	return (starting_count);
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
