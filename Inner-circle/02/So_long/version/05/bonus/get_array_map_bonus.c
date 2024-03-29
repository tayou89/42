/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_array_map_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 22:31:47 by tayou             #+#    #+#             */
/*   Updated: 2023/04/23 22:31:57 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static int	get_fd(char	*map_file_name);
static int	get_line_count(int fd);
static char	**malloc_map(int line_count);
static char	**fill_map(char **map, int fd);

char	**get_array_map(char *map_file_path, t_data *game)
{
	char	**map;

	game->fd = get_fd(map_file_path);
	game->map_line_count = get_line_count(game->fd);
	map = malloc_map(game->map_line_count);
	game->fd = get_fd(map_file_path);
	map = fill_map(map, game->fd);
	return (map);
}

static int	get_fd(char	*map_file_path)
{
	int	fd;

	fd = open(map_file_path, O_RDONLY);
	if (fd < 0)
		exit(0);
	return (fd);
}

static int	get_line_count(int fd)
{
	int		line_count;
	char	*line;

	line_count = 0;
	line = get_next_line(fd);
	while (line != (void *) 0)
	{
		line_count++;
		free(line);
		line = (void *) 0;
		line = get_next_line(fd);
	}
	return (line_count);
}

static char	**malloc_map(int line_count)
{
	char	**map;

	map = (char **) malloc(sizeof(char *) * (line_count + 1));
	if (map == (void *) 0)
		exit(1);
	map[line_count] = (void *) 0;
	return (map);
}

static char	**fill_map(char **map, int fd)
{
	char	*line;
	int		i;

	i = 0;
	line = get_next_line(fd);
	while (line != (void *) 0)
	{
		switch_newline_to_null(line);
		map[i] = ft_strdup(line);
		free(line);
		line = (void *) 0;
		i++;
		line = get_next_line(fd);
	}
	return(map);
}
