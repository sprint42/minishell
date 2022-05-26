#ifndef EXECUTE_H
# define EXECUTE_H

# include <sys/wait.h>
# include <fcntl.h>

# define READ_END 0
# define WRITE_END 1

int		execute_cmds(t_unit_head *cmd_list);
int		check_builtin(t_unit_pipe *cmd);
void	breed_childs(t_unit_head *cmd_lst);
void	wait_childs(t_unit_head *cmd_lst, int **pipe);

int		execute_builtin(t_unit_head *cmd_lst, t_unit_pipe *curr_cmd);

void	redirect(t_unit_rd *rd);

#endif