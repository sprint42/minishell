#include "execute.h"

void sig_int(int sig)
{
	if (sig)
		;
	printf("\n");
	rl_on_new_line();
	rl_replace_line("", 1);
	rl_redisplay();
}