#include "microshell.h"

void	free_data(t_data *data)
{
	if (data->pid != (void *) 0)
		free(data->pid);
	if (data->pipe_fd != (void *) 0)
		free_pipe_fd(data);
}

void	free_pipe_fd(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->count.pipe)
	{
		close(data->pipe_fd[i][0]);
		close(data->pipe_fd[i][1]);
		free(data->pipe_fd[i]);
		i++;
	}
	free(data->pipe_fd);
}
