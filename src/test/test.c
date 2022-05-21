#include "head.h"

////////////////////// Destruct
void	increase(char **s)
{
	(*s)++;
}

void	aa(char *s)
{
	
}

void    test(void)
{
	char    *target;
	t_point	*pck;

	pck = init_struct();
	init_special(pck);
	/* 파싱할 문자열 */
	target = "abcdefg hijklmnop";
	
	while (*target)
	{
		increase(&target);
		break;
	}
}
