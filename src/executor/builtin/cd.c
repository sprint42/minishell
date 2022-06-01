/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejin <yejin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 23:51:35 by yejin             #+#    #+#             */
/*   Updated: 2022/06/02 00:37:37 by yejin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"

char	*extract_home(char **envp)
{
	char	*home;
	int		i;

	if (!envp)
		return (NULL);
	i = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "HOME=", 5) == 0)
			break ;
		i++;
	}
	if (envp[i] == NULL)
		return (NULL);
	home = ft_substr(envp[i], 5, ft_strlen(envp[i]));
	if (home == NULL)
		return (NULL);
	return (home);
}

int	cd_home(t_unit_head *cmd_lst)
{
	char	*home;
	char	**envp;

	envp = make_env_array(cmd_lst);
	if (envp == NULL)
		return (handle_default_error("fail in making env array : cd"));
	home = extract_home(envp);
	free_array_d2(envp);
	if (home == NULL)
		return (handle_default_error("$HOME isn't set : cd"));
	if (chdir(home) < 0)
	{
		free(home);
		return (handle_default_error("fail in chdir : cd"));
	}
	free(home);
	return (0);
}

char	*cd_get_path(t_unit_pipe *curr_cmd)
{
	char	*pwd;
	char	*temp;
	char	*path;

	if (curr_cmd->commands[1][0] != '/')
	{
		pwd = getcwd(NULL, 0);
		if (pwd == NULL)
			return (NULL);
		temp = ft_strjoin(pwd, "/");
		free(pwd);
		if (temp == NULL)
			return (NULL);
		path = ft_strjoin(temp, curr_cmd->commands[1]);
		free(temp);
		if (path == NULL)
			return (NULL);
	}
	else
		path = curr_cmd->commands[1];
	return (path);
}

int	execute_cd(t_unit_head *cmd_lst, t_unit_pipe *curr_cmd)
{
	char	*path;

	if (curr_cmd->commands[1] == NULL)
		return (cd_home(cmd_lst));
	path = cd_get_path(curr_cmd);
	if (path == NULL)
		return (handle_default_error("fail in getting path : cd"));
	if (chdir(path) < 0)
		return (handle_default_error(strerror(errno)));
	free(path);
	return (0);
}
