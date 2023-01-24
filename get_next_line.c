/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 20:19:27 by tayou             #+#    #+#             */
/*   Updated: 2023/01/24 15:38:00 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	check_newline(char *backup, char c)
{
	int	i;

	i = 0;
	while (backup[i] != '\0')
	{
		if (backup[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static void	seperate_backup(char **backup, char **line)
{
	int	newline_point;
	int	i;

	i = 0;
	while ((*backup)[i] != '\n')
		i++;
	newline_point = i;
	*line = ft_substr(*backup, 0, newline_point + 1);
	*backup = ft_substr(*backup, newline_point + 1, ft_strlen(*backup));
}

char	*get_next_line(int fd)
{
	static char	*backup;
	char		buf[BUFFER_SIZE + 1];
	char		*line;
	int			read_size;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	read_size = read(fd, buf, BUFFER_SIZE);
	while (read_size > 0)
	{
		buf[read_size] = '\0';
		if (backup == NULL)
			backup = ft_strdup(buf);
		else
			backup = ft_strjoin(backup, buf);
		if (check_newline(backup, '\n') == 1)
		{
			seperate_backup(&backup, &line);
			return (line);
		}
		read_size = read(fd, buf, BUFFER_SIZE);
	}
	line = ft_strdup(backup);
	return (line);
}
