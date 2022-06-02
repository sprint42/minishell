/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proc_question_mark.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcha <mcha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 20:46:48 by mcha              #+#    #+#             */
/*   Updated: 2022/05/28 20:49:14 by mcha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

char	*proc_question_mark(void)
{
	char	*ret;
	char	*to_num;

	to_num = ft_itoa(g_exit_status);
	ret = ft_strdup(to_num);
	return (ret);
}
