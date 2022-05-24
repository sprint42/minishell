/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcha <mcha@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 18:07:30 by mcha              #+#    #+#             */
/*   Updated: 2022/05/24 13:11:52 by mcha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

static int	find_space(t_point *pck, char c)
{
	char	*tmp;

	tmp = pck->junction->space;
	while (*tmp)
	{
		if (c == *tmp)
			return(1);
		tmp++;
	}
	if (*tmp == 0 && *tmp == c)
		return (1);
	return (0);
}

void	proc_space(t_point *pck, char **s)
{
	char	*cut;

	// Space bit open
	pck->flag |= SPCE;
	// 문자열 슬라이싱
	cut = ft_substr(pck->pile, 0, pck->move - pck->pile);
	cut = ft_strtrim(cut, pck->junction->space);
	if (ft_strlen(cut) > 0)
		link_new_node(pck->parsed_lst, new_node("STR", cut));
		// printf("space  cut: (s)%s(e)\n", cut);
	// move forward until not found space
	while (**s)
	{
		if (!find_space(pck, **s))
			break;
		(*s)++;
	}
	pck->flag -= SPCE;
	pck->pile = *s;
	pck->move = *s;
}


void	proc_null(t_point *pck, char **s)
{
	char	*cut;

	(void)s;
	// printf("isnull s: (s)%s(e)\n", *s);
	// printf("pile: (s)%s(e)\n", pck->pile);
	// printf("move: (s)%s(e)\n", pck->move);
	// cut = ft_substr(pck->pile, 0, pck->move - pck->pile);
	cut = ft_substr(pck->pile, 0, *s - pck->pile);
	cut = ft_strtrim(cut, pck->junction->space);
	// printf("cut: (s)%s(e)\n", cut);
	if (ft_strlen(cut) > 0)
		link_new_node(pck->parsed_lst, new_node("STR", cut));
		// printf("null  cut: (s)%s(e)\n", cut);
}

static int	find_close_squote(char c)
{
	if (c == '\'')
		return (1);
	return (0);
}

// void	proc_squote(t_point *pck, char **s)
// {
// 	char	*cut;

// 	pck->flag |= SNQT;
// 	(*s)++;
// 	while (**s)
// 	{
// 		if (find_close_squote(**s))
// 		{
// 			(*s)++;
// 			break;
// 		}
// 		(*s)++;
// 	}
// 	pck->flag -= SNQT;
// 	pck->move = *s;
// 	cut = ft_substr(pck->pile, 0, pck->move - pck->pile);
// 	if (ft_strlen(cut) > 0)
// 		link_new_node(pck->parsed_lst, new_node("SQUOTE", cut));
// 		// printf("squote cut: (s)%s(e)\n", cut);
// 	pck->pile = *s;
// 	pck->move = *s;
// }

static int	find_close_dquote(char c)
{
	if (c == '\"')
		return (1);
	return (0);
}

// void	proc_dquote(t_point *pck, char **s)
// {
// 	char	*cut;

// 	pck->flag |= DBQT;
// 	(*s)++;
// 	while (**s)
// 	{
// 		if (find_close_dquote(**s))
// 		{
// 			(*s)++;
// 			break;
// 		}
// 		(*s)++;
// 	}
// 	pck->flag -= DBQT;
// 	pck->move = *s;
// 	cut = ft_substr(pck->pile, 0, pck->move - pck->pile);
// 	if (ft_strlen(cut) > 0)
// 		link_new_node(pck->parsed_lst, new_node("DQUOTE", cut));
// 		// printf("dquote cut: (s)%s(e)\n", cut);
// 	pck->pile = *s;
// 	pck->move = *s;
// }

static int	find_trim(t_point *pck, char c)
{
	char	*tmp;

	tmp = pck->junction->trm;
	while (*tmp)
	{
		if (c == *tmp)
			return(1);
		tmp++;
	}
	if (*tmp == 0 && *tmp == c)
		return (1);
	return (0);
}

static int	find_strim(t_point *pck, char c)
{
	char	*tmp;

	tmp = pck->junction->squote_trm;
	while (*tmp)
	{
		if (c == *tmp)
			return (1);
		tmp++;
	}
	if (*tmp == 0 && *tmp == c)
		return (1);
	return (0);
}

static int	find_dtrim(t_point *pck, char c)
{
	char	*tmp;

	tmp = pck->junction->dquote_trm;
	while (*tmp)
	{
		if (c == *tmp)
			return (1);
		tmp++;
	}
	if (*tmp == 0 && *tmp == c)
		return (1);
	return (0);
}

char	*handle_dollar(t_point *pck, char **s, char outer)
{
	char	*ret;
	
	ret = NULL;
	pck->pile = *s;
	if (outer == '\'')
	{
		if (**s == '$')
			(*s)++;
		while (**s && !find_strim(pck, **s))
		{
			(*s)++;
		}
		ret = ft_substr(pck->pile, 0, *s - pck->pile);
		if (**s == '\'')
			(*s)--;
	}
	else if (outer == '\"')
	{
		if (**s == '$')
			(*s)++;
		while (**s && !find_dtrim(pck, **s))
		{
			(*s)++;
		}
		ret = ft_substr(pck->pile, 0, *s - pck->pile);
		// if (**s == '\"')
		// 	(*s)--;
	}
	// printf("return: (s)%s(e)\n", ret);
	return (ret);
}

static int	find_bet_trm(t_point *pck, char c)
{
	char	*tmp;

	tmp = pck->junction->between_trm;
	while (*tmp)
	{
		if (c == *tmp)
			return(1);
		tmp++;
	}
	if (*tmp == 0 && *tmp == c)
		return (1);
	return (0);
}

void	proc_quote(t_point *pck, char **s)
{
	char	*ret;
	char	*tmp;
	char	outer;

	outer = **s;
	// printf("outer: %c\n", outer);
	ret = "";
	// 따옴표 앞의 것 파싱
	ret = ft_strjoin(ret, ft_substr(pck->pile, 0, *s - pck->pile));
	ret = ft_strtrim(ret, pck->junction->space);
	// printf("prev: (s)%s(e)\n", ret);
	// printf("intro: (s)%s(e)\n", *s);
	while (**s && !find_trim(pck, **s))
	{
		// printf("now: (s)%s(e)\n", *s);
		if (outer == 32)
		{
			if (**s == '\'')
				outer = '\'';
			else if (**s == '\"')
				outer = '\"';
			// else
			// {
			// 	// printf("here\n");
			// 	pck->pile = *s;
			// 	// printf("pile: %s\n", pck->pile);
			// 	while (**s && !find_bet_trm(pck, **s))
			// 	{
			// 		(*s)++;
			// 	}
			// 	// printf("s: %c\n", **s);
			// 	ret = ft_strjoin(ret, ft_substr(pck->pile, 0, *s - pck->pile));
			// 	// printf("ret: %s\n", ret);
			// 	(*s)--;
			// }
		}
		if (outer == '\'')
		{
			if (**s == '\'')
				(*s)++;
			pck->pile = *s;
			// printf("ps: (s)%s(e)\n", *s);
			while (**s && !find_close_squote(**s))
			{
				(*s)++;
			}
			// printf("as: (s)%s(e)\n", *s);
			ret = ft_strjoin(ret, ft_substr(pck->pile, 0, *s - pck->pile));
			// printf("sqret: (s)%s(e)\n", ret);
			outer = 32;
		}
		else if (outer == '\"')
		{
			if (**s == '\"')
			{
				(*s)++;
				// printf("afterthat: %c\n", **s);
			}
			while (**s && !find_close_dquote(**s))
			{
				// printf("s: (s)%s(e)\n", *s);
				if (**s != '$')
				{
					ret = ft_strjoin(ret, ft_substr(*s, 0, *s + 1 - *s));
					(*s)++;
				}
				else if (**s == '$')
				{									//////////////// 달러 핸들링
					tmp = handle_dollar(pck, s, outer);
					if (ft_strlen(ft_strtrim(tmp, "$")) == 0)
						ret = ft_strjoin(ret, "$");
					else
					{
						ret = ft_strjoin(ret, "ENVP");
						// printf("ret: (s)%s(e)\n", ret);
						// printf("s: (s)%s(e)\n", *s);
					}
				}
				// printf("s: (s)%s(e)\n", *s);
				// (*s)++;
			}
			outer = 32;
			// printf("dqqret: (s)%s(e)\n", ret);
		}
		else
		{
			// printf("here\n");
			pck->pile = *s;
			// printf("	pile: %s\n", pck->pile);
			while (**s && !find_bet_trm(pck, **s))
			{
				(*s)++;
				// printf("aaaaaaa: %s\n", *s);
			}
			// printf("as: %s\n", *s);
			ret = ft_strjoin(ret, ft_substr(pck->pile, 0, *s - pck->pile));
			// printf("ret: %s\n", ret);
			// (*s)--;
		}
		// printf("outer: %d\n", outer);
		// printf("s: %s\n", *s);
		if (outer == 32 && ((**s) == '\'' || (**s) == '\"'))
			(*s)++;
		// printf("	ret: (s)%s(e)\n", ret);
	}
	// printf("tot: (s)%s(e)\n", ret);
	pck->pile = *s;
	pck->move = pck->pile;
	if (ft_strlen(ret) > 0)
		link_new_node(pck->parsed_lst, new_node("STR", ret));
	// printf("pile: %s\n", pck->pile);
}

static int	find_pipe(char c)
{
	if (c == '|')
		return (1);
	return (0);
}

void	proc_pipe(t_point *pck, char **s)
{
	char	*cut;

	// 파이프 전에 나온 것들 cut
	cut = ft_substr(pck->pile, 0, pck->move - pck->pile);
	cut = ft_strtrim(cut, pck->junction->trm);
	if (ft_strlen(cut) > 0)
		link_new_node(pck->parsed_lst, new_node("STR", cut));
		// printf("prpipe cut: (s)%s(e)\n", cut);
	pck->pile = *s;
	pck->move = *s;
	pck->flag &= 0;
	// 파이프 비트 켜기
	pck->flag |= PIPE;
	while (**s)
	{
		if (!find_pipe(**s))
			break;
		(*s)++;
	}
	cut = ft_substr(pck->pile, 0, *s - pck->pile);
	cut = ft_strtrim(cut, pck->junction->space);
	if (ft_strlen(cut) > 0)
		link_new_node(pck->parsed_lst, new_node("PIPE", cut));
		// printf("nwpipe cut: (s)%s(e)\n", cut);
	(*s)--;
	pck->pile = *s + 1;
	pck->move = *s + 1;
}

static int	find_indirection(char c)
{
	if (c == '<')
		return (1);
	return (0);
}

static int find_outdirection(char c)
{
	if (c == '>')
		return (1);
	return (0);
}

void	proc_inred(t_point *pck, char **s)
{
	char	*cut;

	// 파이프 전에 나온 것들 cut
	cut = ft_substr(pck->pile, 0, pck->move - pck->pile);
	cut = ft_strtrim(cut, pck->junction->trm);
	if (ft_strlen(cut) > 0)
		link_new_node(pck->parsed_lst, new_node("STR", cut));
		// printf("prinrd cut: (s)%s(e)\n", cut);
	pck->pile = *s;
	pck->move = *s;
	while (**s)
	{
		if (!find_indirection(**s))
			break;
		(*s)++;
	}
	cut = ft_substr(pck->pile, 0, *s - pck->pile);
	cut = ft_strtrim(cut, pck->junction->space);
	// printf("cut : (s)%s(e)\n", cut);
	if (ft_strlen(cut) > 0)
	{
		if (!ft_strncmp(cut, "<", 2))
			link_new_node(pck->parsed_lst, new_node("SNIN", cut));
		else if (!ft_strncmp(cut, "<<", 2))
			link_new_node(pck->parsed_lst, new_node("DBIN", cut));
	}
		// link_new_node(pck->parsed_lst, new_node("STR", cut));
		// printf("nwinrd cut: (s)%s(e)\n", cut);
	(*s)--;
	pck->pile = *s + 1;
	pck->move = *s + 1;
}

void	proc_oured(t_point *pck, char **s)
{
	char	*cut;

	// 파이프 전에 나온 것들 cut
	cut = ft_substr(pck->pile, 0, pck->move - pck->pile);
	cut = ft_strtrim(cut, pck->junction->trm);
	if (ft_strlen(cut) > 0)
		link_new_node(pck->parsed_lst, new_node("STR", cut));
		// printf("prourd cut: (s)%s(e)\n", cut);
	pck->pile = *s;
	pck->move = *s;
	while (**s)
	{
		if (!find_outdirection(**s))
			break;
		(*s)++;
	}
	cut = ft_substr(pck->pile, 0, *s - pck->pile);
	// printf("cut : %s\n", cut);
	cut = ft_strtrim(cut, pck->junction->space);
	if (ft_strlen(cut) > 0)
	{
		if (!ft_strncmp(cut, ">", 2))
			link_new_node(pck->parsed_lst, new_node("SNOU", cut));
		else if (!ft_strncmp(cut, ">>", 2))
			link_new_node(pck->parsed_lst, new_node("DBOU", cut));
	}
	(*s)--;
	pck->pile = *s + 1;
	pck->move = *s + 1;
}

static int	find_dollar_trim(t_point *pck, char c)
{
	char	*tmp;

	tmp = pck->junction->trm;
	while (*tmp)
	{
		if (c == *tmp)
			return(1);
		tmp++;
	}
	if (*tmp == 0 && *tmp == c)
		return (1);
	return (0);
}

char	*proc_parse_dollar(t_point *pck, char **s, char *ret)
{
	char	outer;
	char	*tmp;

	outer = **s;
	ret = ft_strtrim(ret, pck->junction->space);;
	while (**s && !find_trim(pck, **s))
	{
		// printf("now: (s)%s(e)\n", *s);
		if (outer == 32)
		{
			if (**s == '\'')
				outer = '\'';
			else if (**s == '\"')
				outer = '\"';
			// else
			// {
			// 	// printf("here\n");
			// 	pck->pile = *s;
			// 	// printf("pile: %s\n", pck->pile);
			// 	while (**s && !find_bet_trm(pck, **s))
			// 	{
			// 		(*s)++;
			// 	}
			// 	// printf("s: %c\n", **s);
			// 	ret = ft_strjoin(ret, ft_substr(pck->pile, 0, *s - pck->pile));
			// 	// printf("ret: %s\n", ret);
			// 	(*s)--;
			// }
		}
		if (outer == '\'')
		{
			if (**s == '\'')
				(*s)++;
			pck->pile = *s;
			// printf("ps: (s)%s(e)\n", *s);
			while (**s && !find_close_squote(**s))
			{
				(*s)++;
			}
			// printf("as: (s)%s(e)\n", *s);
			ret = ft_strjoin(ret, ft_substr(pck->pile, 0, *s - pck->pile));
			// printf("sqret: (s)%s(e)\n", ret);
			outer = 32;
		}
		else if (outer == '\"')
		{
			if (**s == '\"')
			{
				(*s)++;
				// printf("afterthat: %c\n", **s);
			}
			while (**s && !find_close_dquote(**s))
			{
				// printf("s: (s)%s(e)\n", *s);
				if (**s != '$')
				{
					ret = ft_strjoin(ret, ft_substr(*s, 0, *s + 1 - *s));
					(*s)++;
				}
				else if (**s == '$')
				{									//////////////// 달러 핸들링
					tmp = handle_dollar(pck, s, outer);
					if (ft_strlen(ft_strtrim(tmp, "$")) == 0)
						ret = ft_strjoin(ret, "$");
					else
					{
						ret = ft_strjoin(ret, "ENVP");
						// printf("ret: (s)%s(e)\n", ret);
						// printf("s: (s)%s(e)\n", *s);
					}
				}
				// printf("s: (s)%s(e)\n", *s);
				// (*s)++;
			}
			outer = 32;
			// printf("dqqret: (s)%s(e)\n", ret);
		}
		else
		{
			// printf("here\n");
			pck->pile = *s;
			// printf("	pile: %s\n", pck->pile);
			while (**s && !find_bet_trm(pck, **s))
			{
				(*s)++;
				// printf("aaaaaaa: %s\n", *s);
			}
			// printf("as: %s\n", *s);
			ret = ft_strjoin(ret, ft_substr(pck->pile, 0, *s - pck->pile));
			// printf("ret: %s\n", ret);
			// (*s)--;
		}
		// printf("outer: %d\n", outer);
		// printf("s: %s\n", *s);
		if (outer == 32 && ((**s) == '\'' || (**s) == '\"'))
			(*s)++;
		// printf("	ret: (s)%s(e)\n", ret);
	}
	// printf("tot: (s)%s(e)\n", ret);
	pck->pile = *s;
	pck->move = pck->pile;
	return (ret);
}

void	proc_dollar(t_point *pck, char **s)
{
	char	*cut;

	// printf("before pile: (s)%s(e)\n", pck->pile);
	// 달러 이전 내용 파싱
	cut = ft_substr(pck->pile, 0, *s - pck->pile);
	// printf("cut: (s)%s(e)\n", cut);
	// printf("dollar s	: (s)%s(e)\n", *s);
	pck->pile = *s;
	// printf("dollar pile	: (s)%s(e)\n", pck->pile);
	(*s)++;
	while (**s && !find_dollar_trim(pck, **s))
	{
		// printf("inner s	: (s)%s(e)\n", *s);
		if (**s == '\'' || **s == '\"')
		{
			// 달러 파싱
			cut = ft_strjoin(cut, "DOLLAR");
			cut = proc_parse_dollar(pck,  s, cut);
			// cut = ft_strjoin(cut, );
			// printf("now cut : (s)%s(e)\n", cut);
		}
		else
		{
			(*s)++;
		}
		// if (!is_quote(pck, s))
		// 	(*s)++;
	}
	// printf("after s	: (s)%s(e)\n", *s);
	// ft_substr(pck->pile, 0, *s - pck->pile);
	if (ft_strlen(cut) > 0)
		link_new_node(pck->parsed_lst, new_node("STR", cut));
	pck->pile = *s;
	pck->move = *s;
	// printf("cut: %s\n" , cut);
}