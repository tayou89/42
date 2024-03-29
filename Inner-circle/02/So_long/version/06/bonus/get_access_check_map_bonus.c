/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_access_check_map_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 22:31:29 by tayou             #+#    #+#             */
/*   Updated: 2023/04/23 22:31:38 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static char	**malloc_2d_array(char **map);
static void	malloc_1d_array(char **access_check_map, char **map);
static void	initialize_access_check_map_with_x(char **access_check_map);
static int	get_line_count(char **string);

char	**get_access_check_map(char **map)
{
	char	**access_check_map;

	access_check_map = malloc_2d_array(map);
	malloc_1d_array(access_check_map, map);
	initialize_access_check_map_with_x(access_check_map);
	return (access_check_map);
}

static char	**malloc_2d_array(char **map)
{
	char	**access_check_map;
	int		line_count;

	line_count = get_line_count(map);
	access_check_map = (char **) malloc(sizeof(char *) * (line_count + 1));
	if (access_check_map == (void *) 0)
	{
		free_2d_string_array(map);
		exit(1);
	}
	access_check_map[line_count] = (void *) 0;
	return (access_check_map);
}

static void	malloc_1d_array(char **access_check_map, char **map)
{
	int	line_size;
	int	i;

	line_size = ft_strlen(map[0]);
	i = 0;
	while (access_check_map[i] != (void *) 0)
	{
		access_check_map[i] = (char *) malloc(sizeof(char) * line_size + 1);
		if (access_check_map[i] == (void *) 0)
		{
			free_2d_string_array(map);
			free_2d_string_array(access_check_map);
			exit(1);
		}
		access_check_map[i][line_size] = '\0';
		i++;
	}
}

static void	initialize_access_check_map_with_x(char **access_check_map)
{
	int	i;
	int	j;

	i = 0;
	while (access_check_map[i] != (void *) 0)
	{
		j = 0;
		while (access_check_map[i][j] != '\0')
		{
			access_check_map[i][j] = 'X';
			j++;
		}
		i++;
	}
}

static int	get_line_count(char **string)
{
	int	line_count;
	int	i;

	i = 0;
	while (string[i] != (void *) 0)
		i++;
	line_count = i;
	return (line_count);
}
