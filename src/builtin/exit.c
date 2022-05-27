#include "execute.h"

long long	check_first_arg(char *str, int *arg_status)
{
	long long	result;
	int			i;
	int			neg_flag;

	neg_flag = 0;
	if (str[i] == '-')
		neg_flag = 1;
	i = neg_flag - 1;
	while (str[++i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (*arg_status = 1);
	}
	if (i - neg_flag > 14)
		return (*arg_status = 1);
	else if ((i == 15 && ft_strncmp(&(str[neg_flag]), "9223372036854775808", 14) > 0) || \
				i == 14 && ft_strncmp(&(str[neg_flag]), "9223372036854775807", 14) > 0)
		return (*arg_status = 1);
	result = 0;
	i = 0;
	while (str[i])
		result = result * 10 + (str[i++] - '0');
	if (neg_flag)
		return (result * -1);
	return (result);
}

int	execute_exit(t_unit_head *cmd_lst, t_unit_pipe *curr_cmd)
{
	int			arg_status;
	long long	exit_num;

	arg_status = 0;
	exit_num = 0;
	if (curr_cmd->commands[1] != NULL)
		exit_num = check_first_arg(curr_cmd->commands[1], &arg_status);
	if (!arg_status)
	{
		ft_putstr_fd("exit\n", STDERR_FILENO);
		ft_putstr_fd("numeric argument required : exit\n", STDERR_FILENO);
		free_cmd_lst(cmd_lst);
		free_unit_env(cmd_lst);
		exit(255);
	}
	if (!(curr_cmd->commands[1] == NULL || curr_cmd->commands[2] == NULL))
	{
		ft_putstr_fd("exit\n", STDERR_FILENO);
		ft_putstr_fd("too many arguments : exit\n", STDERR_FILENO);
		return (1);
	}
	free_cmd_lst(cmd_lst);
	free_unit_env(cmd_lst);
	exit((unsigned char)exit_num);
}