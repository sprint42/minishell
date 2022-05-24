#include "head.h"

void	judge_special(t_point *pck, char **s)
{
	is_space(pck, s);
	is_quote(pck, s);
	is_pipe(pck, s);
	is_redir(pck, s);
	is_dollar(pck, s);
	
	if (**s != '\'' && **s != '\"')
	{
		pck->move++;
		(*s)++;
	}
	is_null(pck, s);
	// printf("%c, %c\n", *pck->pile, *pck->move);
	// printf("now: %s\n", ft_substr(pck->pile, 0, pck->move - pck->pile + 1));
}

void    test(void)
{
	char    *target;
	t_point	*pck;

	pck = init_struct();
	init_special(pck);
	/* 파싱할 문자열 */
	target = "             one		two args | three| <<  four>	\"	\" \" \" five>>     	$PATH\"$PATH \'abcd\'\"	$PATH\'hello\'world previous quote\'testsquote\' six| asdfasdfasdf\"$PATH it>>is String\' hello trillion world  \'a \"";
	// target = "		  	 	 \"e\"c\'ho\' \"e\'ch\'o\"";
	// target = "export VAR=TEST1";
	// target = "export L2=\"                    $PATH\"";
	// target = "hello \"$world a\"";
	// target = "$\'PA\'TH";

	target = ft_strtrim(target, (char const *)pck->junction->space);
	pck->pile = target;
	pck->move = target;
	while (*target)
	{
		// printf("now : %s\n", target);
		judge_special(pck, &target);
		// printf("aft : %s\n", target);
		// break;
	}

	/* Check parsed list */
	t_parsed	*tmp;

	tmp = pck->parsed_lst->next;
	// while (tmp)
	// {
	// 	printf("PREV_TYPE : %s\n", tmp->prev->type);
	// 	printf("PREV_DATA : %s\n", tmp->prev->str);
	// 	printf("NODE_TYPE : %s\n", tmp->type);
	// 	printf("NODE_DATA : %s\n", tmp->str);
	// 	printf("\n");
	// 	tmp = tmp->next;
	// }
	manufact(pck);
}
