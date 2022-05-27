#include "execute.h"

int	redirect_snin(t_unit_rd *rd)
{
	int	fd;
	
	fd = open(rd->filename, O_RDONLY);
	if (fd < 0)
		return (handle_default_error(strerror(errno)));
	if (dup2(fd, STDIN_FILENO) < 0)
		return (handle_default_error(strerror(errno)));
	close(fd);
	return (0);
}

int	redirect_snout(t_unit_rd *rd)
{
	int	fd;

	fd = open(rd->filename, O_WRONLY | O_TRUNC | O_CREAT, 0644);
	if (fd < 0)
		return (handle_default_error(strerror(errno)));
	if (dup2(fd, STDOUT_FILENO) < 0)
		return (handle_default_error(strerror(errno)));
	close(fd);
	return (0);
}

int	redirect(t_unit_rd *rd)
{
	t_unit_rd	*curr;
	int			ret;

	curr = rd;
	ret = 0;
	while (curr)
	{
		if (curr->rd_type == SNIN)
			ret |= redirect_snin(curr);
		else if (curr->rd_type == SNOU)
			ret |= redirect_snout(curr);
		else if (curr->rd_type == DBIN)
			ret |= redirect_dbin(curr);
		else if (curr->rd_type == DBOU)
			ret |= redirect_dbout(curr);
		curr = curr->next;
	}
	return (ret);
}