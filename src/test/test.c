#include "head.h"

t_unit_head	*test(t_unit_head *head)
{
	char    *target;
	char	*ret;
	char	*tmp_target;
	t_point	*pck;

	pck = init_struct();
	init_special(pck);
	head = malloc_head(pck);
	target = "             one		two args | three| <<  four>	\"	\" \" \" five>>     	$P\'A\'TH\"$PATH \'abcd\'\"	$PATH\'hello\'world previous quote\'testsquote\' six| asdfasdfasdf\"$PATH$USER it>>is String\' hello trillion world  \'a\"b >>YEJIN";
	// target = "   	\'e\'ch\"o\" 	 a      cc >> hello| <<wtf|   b	USER\'$PATH\'wtf\"$HELLO\" 	";
	// // target="hello \"world\"ab|c\'after that\'";
	// // target = "echo \"$PATH\'abc\'hello\"";
	// target = "echo \"<$USER<HELLO\"";
	ret = NULL;

	target = ft_strtrim(target, (char const *)pck->junction->space_trim_set);
	tmp_target = target;
	while (*tmp_target)
	{
		judge_special(pck, &tmp_target, &ret);
	}
	manufact(pck);
	/*
	**	type 가공이 끝난 후 t_unit_head에 파이프 혹은 리다이렉션 단위로 끊어서 연결
	*/
	link_to_head(pck, head);
	free_package(pck);
	free(target);
	// t_unit_pipe	*tmp;

	// tmp = head->pp_next;
	// printf("INTRO\n");
	// while (tmp)
	// {
	// 	while (tmp->commands && *tmp->commands)
	// 	{
	// 		printf("commands	: %s\n", *tmp->commands);
	// 		(tmp->commands)++;
	// 	}
	// 	while (tmp->rd)
	// 	{
	// 		printf("redir		: %s\n", tmp->rd->filename);
	// 		tmp->rd = tmp->rd->next;
	// 	}
	// 	tmp = tmp->pp_next;
	// 	printf("\n");
	// }
	return (head);
}
