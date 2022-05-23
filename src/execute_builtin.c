#include "head.h"
#include "execute.h"

int check_n_flag(char *option_str)
{
	int	i;

	if (option_str == NULL)
		return (1);
	if (option_str[0] != '-')
		return (1);
	i = 0;
	while (option_str[i])
	{
		if (option_str[i] != 'n')
			return (0);
		i++;
	}
	return (1);
}

int execute_echo(t_unit_head *cmd_lst, t_unit_pipe *curr_cmd)
{
	int	i;
	int	n_flag;

	n_flag = check_n_flag(curr_cmd->commands[1]);
	i = 1;
	while (curr_cmd->commands[i])
	{
		ft_putstr_fd(curr_cmd->commands[i], STDOUT_FILENO);
		ft_putchar_fd(' ', STDOUT_FILENO);
		i++;
	}
	if (n_flag)
		ft_putstr_fd('\n', STDOUT_FILENO);
	return (0);
}

int	execute_builtin(t_unit_head *cmd_lst, t_unit_pipe *curr_cmd)
{
	char	*command;

	command = curr_cmd->commands[0];
	redirect(curr_cmd->rd);
	if (ft_strlen(command) == 4 && ft_strncmp(command, "echo", 4) == 0)
		return (execute_echo(cmd_lst, curr_cmd));
	if (ft_strlen(command) == 2 && ft_strncmp(command, "cd", 2) == 0)
		return (execute_cd(cmd_lst, curr_cmd));
	if (ft_strlen(command) == 3 && ft_strncmp(command, "pwd", 3) == 0)
		return (execute_pwd(cmd_lst, curr_cmd));
	if (ft_strlen(command) == 6 && ft_strncmp(command, "export", 6) == 0)
		return (execute_export(cmd_lst, curr_cmd));
	if (ft_strlen(command) == 3 && ft_strncmp(command, "env", 3) == 0)
		return (execute_env(cmd_lst, curr_cmd));
	if (ft_strlen(command) == 4 && ft_strncmp(command, "exit", 4) == 0)
		return (execute_exit(cmd_lst, curr_cmd));
}