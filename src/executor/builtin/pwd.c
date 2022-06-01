/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejin <yejin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 00:38:43 by yejin             #+#    #+#             */
/*   Updated: 2022/06/02 00:38:44 by yejin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"

int	execute_pwd(void)
{
	char	*pwd;

	pwd = getcwd(NULL, 0);
	if (pwd == NULL)
		return (handle_default_error("fail in getcwd : pwd"));
	ft_putstr_fd(pwd, STDOUT_FILENO);
	ft_putchar_fd('\n', STDOUT_FILENO);
	free(pwd);
	return (0);
}
