#ifndef EXECUTE_H
# define EXECUTE_H

# include <sys/wait.h>
# include <fcntl.h>

# define READ_END 0
# define WRITE_END 1
# define EACCESS 2
# define EXIT_FOPEN 1
# define EXIT_CNF 127

int		execute_cmds(t_unit_head *cmd_list);
int		check_builtin(t_unit_pipe *cmd);
int		breed_childs(t_unit_head *cmd_lst);
int		wait_childs(t_unit_head *cmd_lst, int **pipe);

int		execute_builtin(t_unit_head *cmd_lst, t_unit_pipe *curr_cmd);

void	redirect(t_unit_rd *rd);

#endif