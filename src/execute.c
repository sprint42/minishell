#include "head.h"
#include "execute.h"

void	wait_childs(t_child_info child)
{
	int	i;
	int ret;

	i = 0;
	while (i < child.num_of_child)
	{
		ret = waitpid(child.pid[i], &(child.status[i]), 0);
		i++;
	}
	// memory 전부 해제
	// STDIN 복구
	// exit status를 마지막 cmd의 status로 set
}

void	breed_childs(t_unit_head *cmd_lst)
{
	int				i;
	int				fd[2];
	t_child_info	child;

	child.num_of_child = cmd_lst->cmd_cnt;
	child.pid = malloc(sizeof(pid_t) * child.num_of_child);
	child.status = malloc(sizeof(int) * child.num_of_child);
	if (child.pid == NULL || child.status == NULL)
		exit_with_error();
	i = 0;
	// cmd_lst도 같이 순회하면서 해당 cmd에 대해서만 child_process에 넘겨주는 것이 좋을 듯
	while (i < child.num_of_child)
	{
		if (pipe(fd) < 0)
			exit_with_error();
		child.pid[i] = fork();
		if (child.pid[i] < 0)
			exit_with_error();
		if (child.pid[i] == 0)
		{
			child_process();
			return ;
		}
		i++;
	}
	wait_childs(child);
}

int	check_builtin(t_unit_pipe *cmd)
{
	char	*command;

	command = cmd->commands[0];
	if (ft_strlen(command) == 4 && ft_strncmp(command, "echo", 4) == 0)
		return (1);
	if (ft_strlen(command) == 2 && ft_strncmp(command, "cd", 2) == 0)
		return (1);
	if (ft_strlen(command) == 3 && ft_strncmp(command, "pwd", 3) == 0)
		return (1);
	if (ft_strlen(command) == 6 && ft_strncmp(command, "export", 6) == 0)
		return (1);
	if (ft_strlen(command) == 3 && ft_strncmp(command, "env", 3) == 0)
		return (1);
	if (ft_strlen(command) == 4 && ft_strncmp(command, "exit", 4) == 0)
		return (1);
	return (0);
}

void execute_cmds(t_unit_head *cmd_list)
{
	// command가 하나밖에 없고 그 command가 built-in인 경우
	if (cmd_list->cmd_cnt == 1 && check_builtin(cmd_list->pp_next))
	{
		g_exit_status = execute_builtin(cmd_list, cmd_list->pp_next);
		return ;
	}
	// command가 2개 이상이거나
	// 1개라도 built-in이 아니면 fork해서 command를 처리해야 함
	breed_childs(cmd_list);
}