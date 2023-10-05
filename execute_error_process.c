#include "microshell.h"

void	execute_error_process(int error_number, int exit_number, char *path, t_data *data)
{
	char	*error_message;

	error_message = get_error_message(error_number);
	write(2, error_message, ft_strlen(error_message));
	if (path != (void *) 0)
		write(2, path, ft_strlen(path));
	write(2, "\n", 1);
	free_data(data);
}

char 	*get_error_message(int error_number)
{
	if (error_number == SYS_ERROR)
		return ("error: fatal");
	else if (error_number = CD_ARG_ERROR)
		return ("error: cd: bad arguments");
	else if (error_number = CD_PATH_ERROR)
		return ("error: cd: cannot change directory to ");
	else if (error_number = EXECVE_ERROR)
		return ("error: cannot execute ");
}
