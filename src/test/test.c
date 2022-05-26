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
	// t_unit_env	*a;

	// a = pck->env->env_next;
	// while (a->env_next)
	// {
	// 	printf("%s, %s\n", a->key, a->value);
	// 	a = a->env_next;
	// }
	target = "             one		two args | three| <<  four>	\"	\" \" \" five>>     	$P\'A\'TH\"$PATH \'abcd\'\"	$PATH\'hello\'world previous quote\'testsquote\' six| asdfasdfasdf\"$PATH$USER it>>is String\' hello trillion world  \'a\"b";
	// target = "   	\'e\'ch\"o\" 	 a      cc >> hello| <<wtf|   b	USER\'$PATH\'wtf\"$HELLO\" 	";
	// // target="hello \"world\"ab|c\'after that\'";
	// // target = "echo \"$PATH\'abc\'hello\"";
	// target = "echo \"<$USER<HELLO\"";
	ret = NULL;

	target = ft_strtrim(target, (char const *)pck->junction->space_trim_set);
	printf("after target : (s)%s(e)\n", target);
	tmp_target = target;
	while (*tmp_target)
	{
		// printf("now ret : %s\n", ret);
		// printf("%s, %s\n", pck->env->env_next->key, pck->env->env_next->value);
		judge_special(pck, &tmp_target, &ret);
	}
	// t_unit_env	*ptr;

	// ptr = pck->env;
	// while (ptr->env_next)
	// {
	// 	printf("%s, %s\n", ptr->env_next->key, ptr->env_next->value);
	// 	ptr = ptr->env_next;
	// }
	// free(target);
	manufact(pck);
	free_package(pck);
	free(target);
}
