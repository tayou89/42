/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 12:49:30 by tayou             #+#    #+#             */
/*   Updated: 2023/04/06 13:39:17 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include <fcntl.h>
#include <unistd.h>

int	main(int argc, char **argv)
{
	char	*line;
	int		fd;
	int		i;


	if (argc != 2)
		return (0);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		return (0);
	i = 0;
	line = get_next_line(fd);
	while (line != (void *) 0)
	{
		ft_printf("line[%d]: %s", i, line);
		free(line);
		i++;
		line = get_next_line(fd);
	}
	system("leaks a.out");
	return (0);
}
