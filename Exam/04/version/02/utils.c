#include "microshell.h"

int	ft_strlen(char *string)
{
	int	size;
	int	i;

	if (string == (void *) 0)
		return (0);
	i = 0;
	while (string[i] != '\0')
		i++;
	size = i;
	return (size);
}

int	duplicate_fd_1(int object_fd, t_data *data)
{
	int	result_fd;

	result_fd = dup(object_fd);
	if (result_fd == -1)
		execute_error_process(SYS_ERROR, 1, (void *) 0, data);
	return (result_fd);
}

void	duplicate_fd_2(int object_fd, int connect_fd, t_data *data)
{
	if (dup2(object_fd, connect_fd) == -1)
		execute_error_process(SYS_ERROR, 1, (void *) 0, data);
}
