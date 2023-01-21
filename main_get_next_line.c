/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_get_next_line.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 20:33:52 by tayou             #+#    #+#             */
/*   Updated: 2023/01/21 22:02:47 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int	main(void)
{
	char	buf[BUFFER_SIZE + 1];
	char	*string;
	int		fd;
	int		read_size;

	read_size = 0;
	fd = open("./text.txt", O_RDONLY);
	if (fd == -1)
		printf("File Open Error\n");
	while((read_size = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[read_size] = '\0';
		if (string == NULL)
			string = strdup(buf);
		else
			strcat(string, buf);
	}
	printf("%s\n", string);
	close(fd);
	return (0);
}


