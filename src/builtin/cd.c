#include "execute.h"

int	cd_home(void)
{
	char	*path;

	path = getenv("$HOME");
	if (path == NULL)
	{
		ft_putstr_fd("HOME not set : cd", STDOUT_FILENO);
		retrurn (1);
	}
	if (chdir(path) < 0)
		return (handle_default_error(strerror(errno)));
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
			return (handle_default_error(strerror(errno)));
		temp = ft_strjoin(pwd, "/");
		free(pwd);
		if (temp == NULL)
			return (handle_default_error(strerror(errno)));
		path = ft_strjoin(temp, curr_cmd->commands[1]);
		free(temp);
		if (path == NULL)
			return (handle_default_error(strerror(errno)));
	}
	else
		path = curr_cmd->commands[1];
	if (chdir(path) < 0)
		return (handle_default_error(strerror(errno)));
	free(path);
	return (0);
}