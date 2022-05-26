#include "head.h"
#include "execute.h"

char	**extract_path(char **envp, t_unit_pipe *curr_cmd)
{
	char	**path;
	int		i;

	if (!envp)
		handle_child_process_error(1, errno, curr_cmd->commands[0]);
	i = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
			break ;
		i++;
	}
	if (envp[i] == NULL)
		handle_child_process_error(1, errno, curr_cmd->commands[0]);
	path = ft_split(&envp[i][5], ':');
	if (path == NULL)
		handle_child_process_error(1, errno, curr_cmd->commands[0]);
	return (path);
}

void	add_path(t_unit_pipe *curr_cmd, char **path)
{
	char	*temp_path;
	char	*temp_cmd;
	int		i;

	i = 0;
	while (path[i])
	{
		temp_path = ft_strjoin(path[i], "/");
		if (temp_path == NULL)
			handle_child_process_error(1, errno, curr_cmd->commands[0]);
		temp_cmd = ft_strjoin(temp_path, curr_cmd->commands[0]);
		free(temp_path);
		if (temp_cmd == NULL)
			handle_child_process_error(1, errno, curr_cmd->commands[0]);
		if (access(temp_cmd, X_OK) < 0)
			free(temp_cmd);
		else
		{
			free(curr_cmd->commands[0]);
			curr_cmd->commands[0] = temp_cmd;
			return ;
		}
		i++;
	}
}

int	execute_execve(t_unit_head *cmd_lst, t_unit_pipe *curr_cmd, int **pipe_fd, int i)
{
	char	**envp;
	char	**path;

	envp = make_env_array(cmd_lst);
	if (envp == NULL)
		return (handle_child_process_error(1, errno, curr_cmd->commands[0]));
	if (ft_strchr(curr_cmd, '/') == NULL)
	{
		path = extract_path(envp, curr_cmd);
		if (path != NULL)
			add_path(curr_cmd, path);
		free_path(path);
	} 
	execve(curr_cmd->commands[0], curr_cmd->commands, envp);
	// exit_status
}

t_unit_pipe	*find_curr_cmd(t_unit_head *cmd_lst, int i)
{
	t_unit_pipe	*curr_cmd;
	int			j;

	j = 0;
	curr_cmd = cmd_lst->pp_next;
	while (j < i)
	{
		curr_cmd = curr_cmd->pp_next;
		j++;
	}
	return (curr_cmd);
}

int	execute_childprocess(t_unit_head *cmd_lst, int pipe_fd[2], int curr_in, int i)
{
	t_unit_pipe	*curr_cmd;

	curr_cmd = find_curr_cmd(cmd_lst, i);
	close(pipe_fd[0]);
	if (dup2(curr_in, STDIN_FILENO) < 0)
		return (handle_child_process_error(1, errno, curr_cmd->commands[0]));
	close(curr_in);
	if (i != cmd_lst->cmd_cnt - 1)
	{
		if (dup2(pipe_fd[1], STDOUT_FILENO) < 0)
			return (handle_child_process_error(1, errno, curr_cmd->commands[0]));
		close(pipe_fd[1]);
	}
	redirect(curr_cmd->rd);
	if (check_builtin(curr_cmd))
		exit(execute_builtin(cmd_lst, cmd_lst->pp_next));
	execute_execve(cmd_lst, curr_cmd, pipe_fd, i);
}