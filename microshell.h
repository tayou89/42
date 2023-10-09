#ifndef MICROSHELL_H
# define MICROSHELL_H

# include <stdlib.h>
# include <unistd.h>
# include <sys/wait.h>
# include <signal.h>
# include <string.h>

# define SYS_ERROR		0
# define CD_ARGV_ERROR	1
# define CD_PATH_ERROR	2
# define EXECVE_ERROR	3

# define READ		0
# define WRITE		1

# define EVEN_READ	1
# define EVEN_WRITE	0
# define ODD_READ	0
# define ODD_WRITE	1

typedef struct s_count
{
	int	pipe;
	int	child;
}	t_count;

typedef struct s_data
{
	char	**envp;
	pid_t	*pid;
	int		before_fd;
	int		fd[2];
	int		child_number;
	t_count	count;
	int		status;
}	t_data;

void	execute_parent_process(char **argv, t_data *data);

void	execute_child_process(char **parent_string, t_data *data);
void	initialize_child_data(char **parent_string, t_data *data);
void	execve_child_process(int number, char **command, t_data *data);

void	execute_error_process(int error_number, int exit_number, char *message, t_data *data);

int		ft_strlen(char *string);

void	free_data(t_data *data);
void	free_pipe_fd(t_data *data);

#endif
