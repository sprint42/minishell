#include "head.h"

t_unit_head	*test(t_unit_head *head, char *target)
{
	char	*ret;
	char	*tmp_target;
	t_point	*pck;

	pck = init_struct();
	init_special(pck);
	head = malloc_head(pck);
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
	return (head);
}
