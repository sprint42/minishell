#ifndef EXECUTE_H
# define EXECUTE_H

# include <sys/wait.h>
# include <fcntl.h>

typedef struct t_child_info
{
	int		num_of_child;
	pid_t	*pid;
	int		*status;
} t_child_info;

void	execute_cmds(t_unit_head *cmd_list);
int		check_builtin(t_unit_pipe *cmd);
void	breed_childs(t_unit_head *cmd_lst);
void	wait_childs(t_child_info child, t_unit_head *cmd_lst, int **pipe);

int		execute_builtin(t_unit_head *cmd_lst, t_unit_pipe *curr_cmd);

void	redirect(t_unit_rd *rd);

#endif