#include "microshell.h"

char	*get_error_message(int error_number);

void	execute_error_process(int error_number, int exit_number, char *message, t_data *data)
{
	char	*error_message;

	error_message = get_error_message(error_number);
	write(2, error_message, ft_strlen(error_message));
	if (message != (void *) 0)
		write(2, message, ft_strlen(message));
	write(2, "\n", 1);
	if (data != (void *) 0)
		free_data(data);
	exit(exit_number);
}

char	*get_error_message(int error_number)
{
	if (error_number == SYS_ERROR)
		return ("error: fatal");
	else if (error_number == CD_ARGV_ERROR)
		return ("error: cd: bad arguments");
	else if (error_number == CD_PATH_ERROR)
		return ("error: cd: cannot change directory to ");
	else
		return ("error: cannot execute ");
}
