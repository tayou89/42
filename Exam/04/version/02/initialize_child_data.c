#include "microshell.h"

void	get_child_count(char **parent_string, t_data *data);
void	malloc_pid(t_data *data);

void	initialize_child_data(char **parent_string, t_data *data)
{
	get_child_count(parent_string, data);
	malloc_pid(data);
}

void	get_child_count(char **parent_string, t_data *data)
{
	int	i;

	data->count.pipe = 0;
	i = 0;
	while (parent_string[i] != (void *) 0)
	{
		if (strcmp(parent_string[i], "|") == 0)
			data->count.pipe++;
		i++;
	}
	data->count.child = data->count.pipe + 1;
}

void	malloc_pid(t_data *data)
{
	data->pid = (pid_t *) malloc(sizeof(pid_t) * data->count.child);
	if (data->pid == (void *) 0)
		execute_error_process(SYS_ERROR, 1, (void *) 0, (void *) 0);
}
