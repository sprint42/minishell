/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejin <yejin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 00:36:51 by yejin             #+#    #+#             */
/*   Updated: 2022/06/02 00:36:52 by yejin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"

void	sort_env(char **envp)
{
	int		i;
	int		j;
	char	*temp;

	i = 0;
	while (envp[i])
	{
		j = i + 1;
		while (envp[j])
		{
			if (strncmp(envp[i], envp[j], ft_strlen(envp[j]) + 1) > 0)
			{
				temp = envp[i];
				envp[i] = envp[j];
				envp[j] = temp;
			}
			j++;
		}
		i++;
	}
}

char	count_export_env(t_unit_head *cmd_lst)
{
	int			i;
	t_unit_env	*curr;

	i = 0;
	curr = cmd_lst->env_next;
	while (curr)
	{
		i++;
		curr = curr->env_next;
	}
	return (i);
}

char	*make_export_env_line(t_unit_env *curr)
{
	char	*result;
	char	*temp;
	char	*temp2;

	if (curr->value == NULL)
		return (ft_strdup(curr->key));
	temp = ft_strjoin(curr->key, "=\"");
	if (temp == NULL)
		return (NULL);
	temp2 = ft_strjoin(temp, curr->value);
	free(temp);
	if (temp2 == NULL)
		return (NULL);
	result = ft_strjoin(temp2, "\"");
	free(temp2);
	if (result == NULL)
		return (NULL);
	return (result);
}

char	**make_export_env_array(t_unit_head *cmd_lst)
{
	char		**envp;
	int			i;
	t_unit_env	*curr;

	envp = malloc(sizeof(char *) * (count_export_env(cmd_lst) + 1));
	if (envp == NULL)
		return (NULL);
	i = 0;
	curr = cmd_lst->env_next;
	while (curr)
	{
		envp[i] = make_export_env_line(curr);
		if (envp[i] == NULL)
		{
			free_array_d2(envp);
			return (NULL);
		}
		curr = curr->env_next;
		i++;
	}
	envp[i] = NULL;
	return (envp);
}

int	print_env(t_unit_head *cmd_lst)
{
	int		i;
	char	**envp;

	if (cmd_lst->env_next == NULL)
		return (0);
	envp = make_export_env_array(cmd_lst);
	if (envp == NULL)
		return (handle_default_error("fail in making env : export"));
	sort_env(envp);
	i = 0;
	while (envp[i])
	{
		ft_putstr_fd("declare -x ", STDOUT_FILENO);
		ft_putstr_fd(envp[i], STDOUT_FILENO);
		ft_putchar_fd('\n', STDOUT_FILENO);
		i++;
	}
	free_array_d2(envp);
	return (0);
}
