#include "head.h"

void    test(void)
{
	char    *target;
	char	*ret;
	t_point	*pck;

	pck = init_struct();
	init_special(pck);
	// target = "             one		two args | three| <<  four>	\"	\" \" \" five>>     	$P\'A\'TH\"$PATH \'abcd\'\"	$PATH\'hello\'world previous quote\'testsquote\' six| asdfasdfasdf\"$PATH it>>is String\' hello trillion world  \'a\"";
	// target = "   	\'e\'ch\"o\" 	 a      cc >> hello| <<wtf|   b	USER\'$PATH\'wtf\"$HELLO\" 	";
	// target="hello \"world\"ab|c\'after that\'";
	target = "echo \"$PATH\'abc\'hello\"";
	ret = "";

	target = ft_strtrim(target, (char const *)pck->junction->space_trim_set);
	// printf("target: (s)%s(e)\n", target);
	while (*target)
		judge_special(pck, &target, &ret);
}
