#include "execute.h"

int	check_builtin(t_unit_pipe *cmd)
{
	char	*command;

	command = cmd->commands[0];
	if (ft_strlen(command) == 4 && ft_strncmp(command, "echo", 4) == 0)
		return (1);
	if (ft_strlen(command) == 2 && ft_strncmp(command, "cd", 2) == 0)
		return (1);
	if (ft_strlen(command) == 3 && ft_strncmp(command, "pwd", 3) == 0)
		return (1);
	if (ft_strlen(command) == 6 && ft_strncmp(command, "export", 6) == 0)
		return (1);
	if (ft_strlen(command) == 3 && ft_strncmp(command, "env", 3) == 0)
		return (1);
	if (ft_strlen(command) == 4 && ft_strncmp(command, "exit", 4) == 0)
		return (1);
	return (0);
}

int	execute_builtin(t_unit_head *cmd_lst, t_unit_pipe *curr_cmd)
{
	char	*command;

	command = curr_cmd->commands[0];
	if (redirect(curr_cmd->rd) != 0)
		return (1);
	if (ft_strlen(command) == 4 && ft_strncmp(command, "echo", 4) == 0)
		return (execute_echo(curr_cmd));
	if (ft_strlen(command) == 2 && ft_strncmp(command, "cd", 2) == 0)
		return (execute_cd(curr_cmd));
	if (ft_strlen(command) == 3 && ft_strncmp(command, "pwd", 3) == 0)
		return (execute_pwd());
	if (ft_strlen(command) == 6 && ft_strncmp(command, "export", 6) == 0)
		return (execute_export(cmd_lst, curr_cmd));
	if (ft_strlen(command) == 3 && ft_strncmp(command, "env", 3) == 0)
		return (execute_env(cmd_lst, curr_cmd));
	if (ft_strlen(command) == 4 && ft_strncmp(command, "exit", 4) == 0)
		return (execute_exit(cmd_lst, curr_cmd));
	return (1);
}