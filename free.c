#include "microshell.h"

void	free_data(t_data *data)
{
	if (data->pid != (void *) 0)
		free(data->pid);
}
