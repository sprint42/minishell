#include "head.h"

void    test(void)
{
	char    *target;
	char	*ret;
	char	*tmp_target;
	t_point	*pck;

	pck = init_struct();
	init_special(pck);
	init_environ(pck);
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
		judge_special(pck, &tmp_target, &ret);
	}
	manufact(pck);
	/*
	**	type 가공이 끝난 후 t_unit_head에 파이프 혹은 리다이렉션 단위로 끊어서 연결
	*/
	/*
		
	*/
	free_package(pck);
	free(target);
}
