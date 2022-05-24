#include "head.h"
#include "execute.h"

static	void	sort_env(char **envp)
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
			if (strncmp(envp[i], envp[j]) > 0)
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

// 나중에 2차원 배열을 통일적으로 free 시키는 함수를 만드는 것이 더 좋을 듯
static void	**free_copy_env(char **envp)
{
	int	i;

	if (envp == NULL)
		return ;
	i = 0;
	while (envp[i])
		free(envp[i++]);
	free(envp);
}

static char	**copy_env(t_unit_head *cmd_lst)
{
	int		i;
	char	**envp;

	if (cmd_lst->envp == NULL)
		return (NULL);
	i = 0;
	while(cmd_lst->envp[i])
		i++;
	envp = malloc(sizeof(char *) * (i + 1));
	if (envp == NULL)
		exit_with_error();
	i = 0;
	while (cmd_lst->envp[i])
	{
		envp[i] = malloc(sizeof(char) * (ft_strlen(cmd_lst->envp) + 1);
		if (envp[i] == NULL)
		{
			free_copy_env(envp);
			exit_with_error();
		}
		ft_strlcpy(envp[i], cmd_lst->envp[i], ft_strlen(cmd_lst->envp) + 1);
		i++;
	}
	return (envp);
}

static int	print_env(t_unit_head *cmd_lst)
{
	int		i;
	char	**envp;
	
	envp = copy_env(cmd_lst);
	if (envp == NULL)
		exit_with_error();
	sort_env(envp);
	i = 0;
	while (envp[i])
	{
		ft_putstr_fd(envp[i], STDOUT_FILENO);
		i++;
	}
	free_copy_env(envp);
	return (0);
}

static int	add_env(t_unit_head *cmd_lst, char *new_env)
{
	
}

int	execute_export(t_unit_head *cmd_lst, t_unit_pipe *curr_cmd)
{
	int	i;
	int	exit_code;

	if (curr_cmd->commands[1] == NULL)
		return (print_env(cmd_lst));
	i = 0;
	exit_code = 0;
	while (curr_cmd->commands[i])
	{
		if (ft_strchr(curr_cmd->commands[i], '=') != NULL)
		{
			if (!ft_isalpha(curr_cmd->commands[i][0]))
			{
				ft_putstr_fd("not a valid identifier\n", STDOUT_FILENO);
				exit_code = 1;
			}
			else
			{
				if (add_env(cmd_lst, curr_cmd->commands[i]) < 0)
					return (1);
			}
		}
		i++;
	}
	return (exit_code);
}