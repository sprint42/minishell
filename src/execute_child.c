#include "head.h"
#include "execute.h"

int	execute_execve(t_unit_head *cmd_lst, t_unit_pipe *curr_cmd, int **pipe_fd, int i)
{
	char	**envp;

	envp = make_env_array(cmd_lst);
	if (envp == NULL)
		return (handle_child_process_error(1, errno, curr_cmd->commands[0]));
	// 환경변수 parsing 하고 호출, exit_status 처리
	// execve(curr_cmd->commands[0], curr_cmd->command, envp)
}

int	execute_childprocess(t_unit_head *cmd_lst, t_unit_pipe *curr_cmd, int **pipe_fd, int i)
{
	if (i != 0)
	{
		if (dup2(pipe_fd[i - 1][READ_END], STDIN_FILENO) < 0)
			return (handle_child_process_error(1, errno, curr_cmd->commands[0]));
		close(pipe_fd[i - 1][READ_END]);
	}
	if (i != cmd_lst->cmd_cnt - 1)
	{
		if (dup2(pipe_fd[i - 1][WRITE_END], STDOUT_FILENO) < 0)
			return (handle_child_process_error(1, errno, curr_cmd->commands[0]));
		close(pipe_fd[i - 1][WRITE_END]);
	}
	redirect(curr_cmd->rd);
	if (check_builtin(curr_cmd))
		exit(execute_builtin(cmd_lst, cmd_lst->pp_next));
	execute_execve(cmd_lst, curr_cmd, pipe_fd, i);
}