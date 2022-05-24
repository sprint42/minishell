/* ************************************************************************** */	
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   head.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcha <mcha@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 13:32:42 by mcha              #+#    #+#             */
/*   Updated: 2022/05/21 15:59:30 by mcha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEAD_H
# define HEAD_H

/*
**  system header
*/
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <signal.h>

# include "../libft/libft.h"

int	g_exit_status;

/*
**	분기가 일어나는 포인트
**	문자열, 공백, 작은 따옴표, 큰 따옴표, 백슬래쉬, 달러, 파이프, 더블 파이프, 세미콜론, <, >, <<, >>
*/

enum e_split_point
{
	STRS = 1 << 0,
	SPCE = 1 << 1,
	SNQT = 1 << 2,
	DBQT = 1 << 3,
	BSLA = 1 << 4,
	DOLR = 1 << 5,
	PIPE = 1 << 6,
	DPIP = 1 << 7,
	SEMC = 1 << 8,
	SNIN = 1 << 9,
	SNOU = 1 << 10,
	DBIN = 1 << 11,
	DBOU = 1 << 12,
	COMM = 1 << 13
};

/*
**	리다이렉션 종류
**	IN	: < 뒤에 있는 파일 명
**	OUT	: > 뒤에 있는 파일 명
*/
enum e_redirection_type
{
	IN = 1,
	OUT
};

/*
**	리다이렉션 유닛
**	int			rd_type		: 리다이렉션의 타입
**	char		*filename	: 리다이렉션의 파일 명
**	t_unit_rd	*next		: 다음 리다이렉션 요소의 주소
*/
typedef struct t_unit_rd
{
	int					rd_type;
	char				*filename;
	struct t_unit_rd	*next;
}	t_unit_rd;

/* 
**	파이프 유닛
**	char		**commands	: 명령어 테이블
**	t_unit_rd	*rd			: redirect 연결 리스트 도입부(시작점) 주소
**	t_unit_pipe	**pp_next	: 다음 파이프 유닛의 주소
*/
typedef struct t_unit_pipe
{
	char				**commands;
	struct t_unit_rd	*rd;
	struct t_unit_pipe	*pp_next;
}	t_unit_pipe;

/*
** child info를 저장할 수 있는 구조체
** pid_t	*pid	: 각 child별 pid 저장
** int		*status	: 각 child별 종료 status 저장
*/
typedef struct t_child_info
{
	pid_t	*pid;
	int		*status;
} t_child_info;

// envp랑, 분할한 path 정보도 있으면 좋을 듯
typedef struct t_unit_head
{
    int                 cmd_cnt;
	char				**path;
    struct t_unit_pipe  *pp_next;
	char				**envp;
	t_child_info		child;
} t_unit_head;

/*
**	2022. 05. 21
**	author : mcha
**	Description : 파싱 테스트 부분
*/

/*
**	구조체
*/

typedef struct t_special
{
	char	*space;
	char	*trm;
	char	*squote_trm;
	char	*dquote_trm;
	char	*between_trm;
	char	*dollar_trm;
}t_special;

typedef struct t_parsed
{
	char	*type;
	char	*str;
	struct t_parsed	*prev;
	struct t_parsed	*next;
}t_parsed;

typedef struct t_point
{
	int			flag;
	char		*prev;
	char		*pile;
	char		*move;
	t_special	*junction;
	t_parsed	*parsed_lst;
}t_point;


/*
**	사용자 함수
*/
void		test(void);
t_point		*init_struct(void);
void		init_special(t_point *ptr);
t_point		*malloc_point(t_point *ptr);
t_special	*malloc_junction(t_special *ptr);
t_parsed	*malloc_parsed(t_parsed *ptr);

// judge
void	is_space(t_point *pck, char **s);
void	is_null(t_point *pck, char **s);
void	proc_space(t_point *pck, char **s);
void	proc_null(t_point *pck, char **s);

int		is_quote(t_point *pck, char **s);
void	proc_quote(t_point *pck, char **s);
// void	proc_squote(t_point *pck, char **s);
// void	proc_dquote(t_point *pck, char **s);

void	is_pipe(t_point *pck, char **s);
void	proc_pipe(t_point *pck, char **s);

void	is_redir(t_point *pck, char **s);
void	proc_oured(t_point *pck, char **s);
void	proc_inred(t_point *pck, char **s);

t_parsed	*new_node(char *type, char *str);
void	link_new_node(t_parsed *og, t_parsed *new);

void	manufact(t_point *ptr);
void	manufact_type(t_parsed **tmp, t_point *ptr);

void	is_dollar(t_point *pck, char **s);
void	proc_dollar(t_point *pck, char **s);
// void	str_handler(t_parsed *tmp, t_point *ptr);

/*
**	End of parsing test session
*/

#endif
