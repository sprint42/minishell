#include "head.h"
#include "execute.h"

void	wait_childs(t_child_info child, t_unit_head *cmd_lst, int **pipe)
{
	int	i;
	int ret;

	i = 0;
	while (i < child.num_of_child)
	{
		ret = waitpid(child.pid[i], &(child.status[i]), 0);
		i++;
	}
	// memory 전부 해제 (child, cmd_lst 전부) + pipe도..
	// STDIN 복구
	// exit status를 마지막 cmd의 status로 set
}

int	**generate_pipe(int cmd_cnt)
{
	int	**pipe_fd;
	int	i;
	int	j;

	pipe_fd = malloc(sizeof(int *) * (cmd_cnt - 1));
	if (pipe_fd == NULL)
		return (0);
	i = 0;
	while (i < cmd_cnt - 1)
	{
		pipe_fd[i] = malloc(sizeof(int) * 2);
		if (pipe_fd[i] == NULL)
		{
			j = 0;
			while (j < i)
				free(pipe_fd[j++]);
			free(pipe_fd);
			return (0);
		}
		i++;
	}
	return (pipe_fd);
}

void	breed_childs(t_unit_head *cmd_lst)
{
	int				i;
	int				**pipe_fd;
	t_unit_pipe		*curr_cmd;
	t_child_info	child;

	child.num_of_child = cmd_lst->cmd_cnt;
	child.pid = malloc(sizeof(pid_t) * child.num_of_child);
	child.status = malloc(sizeof(int) * child.num_of_child);
	pipe_fd = generate_pipe(cmd_lst->cmd_cnt);
	if (child.pid == NULL || child.status == NULL || pipe_fd == NULL)
		exit_with_error();
	i = 0;
	// cmd_lst도 같이 순회하면서 해당 cmd에 대해서만 child_process에 넘겨주는 것이 좋을 듯
	curr_cmd = cmd_lst->pp_next;
	while (i < child.num_of_child)
	{
		if (pipe(pipe_fd[i]) < 0)
			exit_with_error();
		child.pid[i] = fork();
		if (child.pid[i] < 0)
			exit_with_error();
		if (child.pid[i] == 0)
		{
			child_process();
			return ;
		}
		curr_cmd = curr_cmd->pp_next;
		i++;
	}
	wait_childs(child, cmd_lst, pipe);
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
		// 메모리 해제
		return ;
	}
	// command가 2개 이상이거나
	// 1개라도 built-in이 아니면 fork해서 command를 처리해야 함
	breed_childs(cmd_list);
}