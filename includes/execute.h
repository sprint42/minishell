#ifndef EXECUTE_H
# define EXECUTE_H

# include <sys/wait.h>

typedef struct t_child_info
{
	int		num_of_child;
	pid_t	*pid;
	int		*status;
} t_child_info;

#endif