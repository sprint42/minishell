#include "head.h"
#include "execute.h"

void	redirect_snin(t_unit_rd *rd)
{
	int	fd;
	
	fd = open(rd->filename, O_RDONLY);
	if (fd < 0)
		exit_with_error();
	if (dup2(fd, STDIN_FILENO) < 0)
		exit_with_error();
	close(fd);
}

void	redirect_snout(t_unit_rd *rd)
{
	int	fd;

	fd = open(rd->filename, O_WRONLY | O_TRUNC | O_CREAT, 0644);
	if (fd < 0)
		exit_with_error();
	if (dup2(fd, STDOUT_FILENO) < 0)
		exit_with_error();
	close(fd);
}

void	redirect(t_unit_rd *rd)
{
	t_unit_rd	*curr;

	curr = rd;
	while (curr)
	{
		if (curr->rd_type == SNIN)
			redirect_snin(curr);
		else if (curr->rd_type == SNOU)
			redirect_snout(curr);
		else if (curr->rd_type == DBIN)
			redirect_dbin(curr);
		else if (curr->rd_type == DBOU)
			redirect_dbout(curr);
		curr = curr->next;
	}
}