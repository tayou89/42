/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 20:19:27 by tayou             #+#    #+#             */
/*   Updated: 2023/01/22 00:42:44 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_check_newline(char *backup, char c)
{
	int	i;

	i = 0;
	while (backup[i] != '\0')
	{
		if (backup[i] == c)
			return (i);
		i++;
	}
	return (0);
}

char	*get_next_line(int fd)
{
	char		buf[BUFFER_SIZE + 1];
	static char	*backup
	char		*line;
	int			read_size;
	int			cut_size;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	while ((read_size = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[read_size] = '\0';
		if (backup == NULL)
			backup = ft_strdup(buf);
		else
			backup = ft_strjoin(backup, buf);
		cut_size = ft_check_newline(backup, '\n');
		if (cut_size != 0)
		{
			line = ft_substr(backup, 0, cut_size);
			backup = ft_strchr(backup, '\n') + 1;
		}
		else
			line = ft_strdup(backup);
	}


		
