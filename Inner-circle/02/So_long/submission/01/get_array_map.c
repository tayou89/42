/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_array_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 14:05:19 by tayou             #+#    #+#             */
/*   Updated: 2023/05/03 14:09:13 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	get_fd(t_data *game);
static void	get_line_count(t_data *game);
static void	malloc_map(t_data *game);
static void	fill_map(t_data *game);

void	get_array_map(t_data *game)
{
	get_fd(game);
	get_line_count(game);
	malloc_map(game);
	get_fd(game);
	fill_map(game);
}

static void	get_fd(t_data *game)
{
	game->map.fd = open(game->map.file_path, O_RDONLY);
	if (game->map.fd < 0)
		exit(0);
}

static void	get_line_count(t_data *game)
{
	int		line_count;
	char	*line;

	line_count = 0;
	line = get_next_line(game->map.fd);
	while (line != (void *) 0)
	{
		line_count++;
		free(line);
		line = (void *) 0;
		line = get_next_line(game->map.fd);
	}
	game->map.line_count = line_count;
}

static void	malloc_map(t_data *game)
{
	game->map.array \
		= (char **) malloc(sizeof(char *) * (game->map.line_count + 1));
	if (game->map.array == (void *) 0)
		exit(1);
	game->map.array[game->map.line_count] = (void *) 0;
}

static void	fill_map(t_data *game)
{
	char	*line;
	int		i;

	i = 0;
	line = get_next_line(game->map.fd);
	while (line != (void *) 0)
	{
		switch_newline_to_null(line);
		game->map.array[i] = ft_strdup(line);
		free(line);
		line = (void *) 0;
		i++;
		line = get_next_line(game->map.fd);
	}
}
