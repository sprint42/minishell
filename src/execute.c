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