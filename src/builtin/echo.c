# include "execute.h"

int echo_check_newline(char *option_str)
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
	i = n_flag + 1;
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