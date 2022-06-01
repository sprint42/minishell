# include "execute.h"

int echo_check_newline(char *option_str)
{
	int	i;

	if (option_str == NULL)
		return (1);
	if (option_str[0] != '-')
		return (1);
	i = 1;
	while (option_str[i])
	{
		if (option_str[i] != 'n')
			return (1);
		i++;
	}
	return (0);
}

int execute_echo(t_unit_pipe *curr_cmd)
{
	int	i;
	int	n_flag;

	n_flag = echo_check_newline(curr_cmd->commands[1]);
	if (n_flag)
		i = 1;
	else
		i = 2;
	while (curr_cmd->commands[i])
	{
		ft_putstr_fd(curr_cmd->commands[i], STDOUT_FILENO);
		if (curr_cmd->commands[i + 1])
			ft_putchar_fd(' ', STDOUT_FILENO);
		i++;
	}
	if (n_flag)
		ft_putchar_fd('\n', STDOUT_FILENO);
	return (0);
}