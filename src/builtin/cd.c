#include "execute.h"

int	cd_home(void)
{
	char	*path;

	path = getenv("$HOME");
	if (path == NULL)
	{
		ft_putstr_fd("HOME not set\n", STDOUT_FILENO);
		retrurn (1);
	}
	if (chdir(path) < 0)
		exit_with_error();
	free(path);
	return (0); 
}

int	execute_cd(t_unit_head *cmd_lst, t_unit_pipe *curr_cmd)
{
	char	*pwd;
	char	*temp;
	char	*path;
	
	if (curr_cmd->commands[1] == NULL)
		return (execute_cd_home());
	if (curr_cmd->commands[1][0] != '/')
	{
		pwd = getcwd(NULL, 0);
		if (pwd == NULL)
			exit_with_error();
		temp = ft_strjoin(pwd, "/");
		free(pwd);
		if (temp == NULL)
			exit_with_error();
		path = ft_strjoin(temp, curr_cmd->commands[1]);
		free(temp);
		if (path == NULL)
			exit_with_error();
	}
	else
		path = curr_cmd->commands[1];
	if (chdir(path) < 0) // file이 없는 경우 에러가 아니라 return (1)?
		exit_with_error();
	free(path);
	return (0);
}