#include "execute.h"

void	sig_handler(int signal)
{
	if (signal == SIGINT)
	{
		write(STDOUT_FILENO, "\n", 1);
		rl_replace_line("", 0);
		rl_on_new_line();
		rl_redisplay();
		g_exit_status = 1;
	}
	else if (signal == SIGQUIT)
	{
		rl_on_new_line();
		rl_redisplay();
	}
}

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