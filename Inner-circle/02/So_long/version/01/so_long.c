/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 22:22:33 by tayou             #+#    #+#             */
/*   Updated: 2023/04/12 10:42:50 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_argc(int argc);
char	**get_map(char *map_file_name);
int		get_fd(char	*map_file_name);
int		get_line_count(int fd);
char	**malloc_map(int line_count);
char	**fill_map(char **map, int fd);

int	main(int argc, char **argv)
{
	char	**map;
	int		i;

	check_argc(argc);
	map = get_map(argv[1]);
	i = 0;
	while (map[i] != (void *) 0)
	{
		ft_printf("map[%d]: %s", i, map[i]);
		i++;
	}
	free_2d_string_array(map);
	system("leaks so_long");
	return (0);
}

void	check_argc(int argc)
{
	if (argc != 2)
		exit(0);
}

char	**get_map(char *map_file_name)
{
	char	**map;
	int		fd;
	int		line_count;

	fd = get_fd(map_file_name);
	line_count = get_line_count(fd);
	map = malloc_map(line_count);
	fd = get_fd(map_file_name);
	map = fill_map(map, fd);
	return (map);
}

int	get_fd(char	*map_file_name)
{
	int	fd;

	fd = open(map_file_name, O_RDONLY);
	if (fd < 0)
		exit(0);
	return (fd);
}

int	get_line_count(int fd)
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

char	**malloc_map(int line_count)
{
	char	**map;

	map = (char **) malloc(sizeof(char *) * (line_count + 1));
	if (map == (void *) 0)
		exit(1);
	map[line_count] = (void *) 0;
	return (map);
}

char	**fill_map(char **map, int fd)
{
	char	*line;
	int		i;

	i = 0;
	line = get_next_line(fd);
	while (line != (void *) 0)
	{
		map[i] = line;
		i++;
		line = get_next_line(fd);
	}
	return(map);
}

/*
void	check_map_validation(int argc, char **argv)
{
	char	**map;

	if (argc != 2)
		exit(0);
	

}
*/
