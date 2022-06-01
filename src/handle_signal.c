#include "execute.h"

void	sig_child_handler(int signal)
{
	if (signal == SIGINT)
		ft_putchar_fd('\n', 2);
	if (signal == SIGQUIT)
		ft_putstr_fd("Quit\n", 2);
}

void	sig_heredoc_handler(int signal)
{
	if (signal == SIGINT)
		;
}