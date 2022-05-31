#include "execute.h"

void sig_child_handler(int signal)
{
	if (signal == SIGINT)
		ft_putchar_fd('\n', 2);
}