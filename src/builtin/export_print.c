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

char	count_env(t_unit_head *cmd_lst)
{
	int			i;
	t_unit_env	*curr;

	i = 0;
	curr = cmd_lst->env_next;
	while (curr)
	{
		i++;
		if (curr->env_next)
			break ;
		curr = curr->env_next;
	}
	return (i);
}

void	free_env_array(char **envp)
{
	int	i;

	if (envp)
	{
		i = 0;
		while (envp[i])
			free(envp[i++]);
		free(envp);
	}
}

char	**make_env_array(t_unit_head *cmd_lst)
{
	char		**envp;
	int			i;
	t_unit_env	*curr;

	envp = malloc(sizeof(char *) * (count_env(cmd_lst) + 1));
	if (envp == NULL)
		return (NULL);
	i = 0;
	curr = cmd_lst->env_next;
	while (curr)
	{
		envp[i] = malloc(sizeof(char) *  (ft_strlen(curr->key) + ft_strlen(curr->value) + 2));
		if (envp[i] == NULL)
		{
			free_env_array(envp);
			return (NULL);
		}
		ft_strlcpy(envp[i], curr->key, ft_strlen(curr->key) + ft_strlen(curr->value) + 2);
		ft_strlcat(envp[i], "=", ft_strlen(curr->key) + ft_strlen(curr->value) + 2);
		ft_strlcat(envp[i], curr->value, ft_strlen(curr->key) + ft_strlen(curr->value) + 2);
		if (curr->env_next)
			break ;
		curr = curr->env_next;
	}
	return (envp);
}

int	print_env(t_unit_head *cmd_lst)
{
	int		i;
	char	**envp;
	
	if (cmd_lst->env_next == NULL)
		return (0);
	envp = make_env_array(cmd_lst);
	if (envp == NULL)
		return (handle_default_error("fail in making envp : export"));
	sort_env(envp);
	i = 0;
	while (envp[i])
	{
		ft_putstr_fd("declare -x ", STDOUT_FILENO);
		ft_putstr_fd(envp[i], STDOUT_FILENO);
		ft_putchar_fd('\n', STDOUT_FILENO);
		i++;
	}
	free_env_array(envp);
	return (0);
}