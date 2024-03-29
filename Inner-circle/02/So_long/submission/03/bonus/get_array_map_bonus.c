/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_array_map_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 18:47:22 by tayou             #+#    #+#             */
/*   Updated: 2023/05/16 21:41:22 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	get_fd(t_data *game);
static void	get_line_count(t_data *game);
static void	malloc_map(t_data *game);
static void	fill_map(t_data *game);

void	get_array_map(t_data *game)
{
	get_fd(game);
	get_line_count(game);
	if (game->map.line_count == 0)
		return ;
	malloc_map(game);
	get_fd(game);
	fill_map(game);
}

static void	get_fd(t_data *game)
{
	game->map.fd = open(game->map.file_path, O_RDONLY);
	if (game->map.fd < 0)
		execute_process_for_open_error(game);
}

static void	get_line_count(t_data *game)
{
	char	buf[BUF_SIZE];
	int		read_size;
	int		count;

	game->map.line_count = 0;
	read_size = read(game->map.fd, buf, BUF_SIZE);
	if (read_size == -1)
		execute_process_for_read_error();
	while (read_size != 0)
	{
		count = 0;
		count = count_line_in_string(buf, read_size);
		game->map.line_count += count;
		read_size = read(game->map.fd, buf, BUF_SIZE);
		if (read_size == -1)
			execute_process_for_read_error();
		if (read_size == 0 && count == 0)
			game->map.line_count++;
	}
}

static void	malloc_map(t_data *game)
{
	int	i;

	game->map.array \
		= (char **) malloc(sizeof(char *) * (game->map.line_count + 1));
	if (game->map.array == (void *) 0)
		execute_process_for_malloc_array_error(game);
	i = 0;
	while (i < game->map.line_count)
	{
		game->map.array[i] = (void *) 0;
		i++;
	}
	game->map.array[game->map.line_count] = (void *) 0;
}

static void	fill_map(t_data *game)
{
	int		i;

	i = 0;
	while (i < game->map.line_count)
	{
		game->map.line = get_next_line(game->map.fd);
		if (game->map.line == (void *) 0)
			execute_process_for_malloc_array_error(game);
		switch_newline_to_null(game->map.line);
		game->map.array[i] = ft_strdup(game->map.line);
		if (game->map.array[i] == (void *) 0)
			execute_process_for_malloc_array_error(game);
		free(game->map.line);
		game->map.line = (void *) 0;
		i++;
	}
}
