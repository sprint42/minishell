#include "execute.h"

void	sig_after_readline_handler(int signal)
{
	if (signal == SIGINT)
		ft_putchar_fd('\n', 2);
	if (signal == SIGQUIT)
		ft_putchar_fd('\n', 2);
}

void	sig_child_handler(int signal)
{
	if (signal == SIGINT)
		exit(2);
}