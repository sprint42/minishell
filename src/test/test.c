#include "head.h"

void    test(void)
{
	char    *target;
	char	*ret;
	char	*tmp_target;
	t_point	*pck;
	// (void)target;
	// (void)ret;
	// (void)tmp_target;

	pck = init_struct();
	init_special(pck);
	init_environ(pck);
	// target = "             one		two args | three| <<  four>	\"	\" \" \" five>>     	$P\'A\'TH\"$PATH \'abcd\'\"	$PATH\'hello\'world previous quote\'testsquote\' six| asdfasdfasdf\"$PATH it>>is String\' hello trillion world  \'a\"b";
	// // target = "   	\'e\'ch\"o\" 	 a      cc >> hello| <<wtf|   b	USER\'$PATH\'wtf\"$HELLO\" 	";
	// // target="hello \"world\"ab|c\'after that\'";
	// // target = "echo \"$PATH\'abc\'hello\"";
	target = "echo \"<$PATH<HELLO\"";
	ret = NULL;

	target = ft_strtrim(target, (char const *)pck->junction->space_trim_set);
	tmp_target = target;
	while (*tmp_target)
	{
		printf("now target : %s\n", tmp_target);
		printf("now ret : %s\n", ret);
		printf("\n");
		judge_special(pck, &tmp_target, &ret);
	}
	// free(target);
	// manufact(pck);
	free_package(pck);
}
