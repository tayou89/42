/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 22:22:33 by tayou             #+#    #+#             */
/*   Updated: 2023/04/06 21:59:07 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	char	**map;

	check_argc(argc);
	map = get_map(argv[1]);
	check_map_validation(argc, argv);
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
	fill_map(map, fd);


}

int	get_fd(char	*map_file_name)
{
	int	fd;

	fd = open(map_file_name, O_RDONLY);
	if (fd < 0)
		exit(0);
	return (fd);
}

char	**malloc_map(int line_count)
{
	char	**map;

	map = (char **) malloc(sizeof(char *) * (line_count + 1));
	if (map == (void **) 0)
		exit(1);
	map[line_count] = '\0';
	return (map);
}

void	fill_map(char **map, int fd)
{
	char	*line;
	int		i;

	line = get_next_line(fd);
	while (line != (void *) 0)
	{
		map[i] = 


int	get_line_count(int fd)
{
	int	line_count;

	line_count = 0;
	while (get_next_line(fd) != (void *) 0)
		line_count++;
	return (line_count);
}

void	check_map_validation(int argc, char **argv)
{
	char	**map;

	if (argc != 2)
		exit(0);
	

}	


