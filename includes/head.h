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
# include <errno.h>

# include "../libft/libft.h"

unsigned char	g_exit_status;

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

/*
** 환경변수를 저장할 수 있는 구조체
*/
typedef struct t_unit_env
{
	char				*key;
	char				*value;
	struct t_unit_env	*env_next;
} t_unit_env;

typedef struct t_unit_head
{
    int                 cmd_cnt;
    struct t_unit_pipe  *pp_next;
	struct t_unit_env	*env_next;
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
	char	*dolr_trim_set;
	char	*space_trim_set;
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
	t_unit_env	*env;
	t_parsed	*parsed;
	t_special	*junction;
}t_point;


/*
**	사용자 함수
*/
t_unit_env		*malloc_env(void);
t_point			*init_struct(void);
t_point			*malloc_point(void);
t_parsed		*malloc_parsed(void);
t_special		*malloc_junction(void);
t_unit_head		*test(t_unit_head *head);
t_unit_head		*malloc_head(t_point *pck);
void			init_special(t_point *ptr);
void			init_environ(t_point *pck);

/*
**	judge special
*/
void			judge_special(t_point *pck, char **s, char **ret);

/*
**	is special word?
*/
int				is_null(char c);
int				is_pipe(t_point *pck, char c);
int				is_redr(t_point *pck, char c);
int				is_dolr(t_point *pck, char c);
int				is_quot(t_point *pck, char c);
int				is_space(t_point *pck, char c);

/*
**	find
*/
int				find_pipe(t_point *pck, char c);
int				find_wspace(t_point *pck, char c);
int				find_dolr_trim(t_point *pck, char c);
int				find_redr(t_point *pck, char c, char redr);

/*
**	process
*/
void			proc_null(t_point *pck, char **ret);
void			proc_pipe(t_point *pck, char **s, char **ret);
void			proc_dolr(t_point *pck, char **s, char **ret);
void			proc_space(t_point *pck, char **s, char **ret);
void			proc_redr(t_point *pck, char **s, char **ret, char redr);
void			proc_quot(t_point *pck, char **s, char **ret, char quot);


/*
**	Node
*/
void			manufact(t_point *ptr);
t_parsed		*new_node(char *type, char *str);
t_unit_env		*new_env_node(char *key, char *value);
char			*ret_env_value(t_point *pck, char *key);
t_unit_rd		*new_rd_node(int rd_type, char *filename);
void			link_new_node(t_parsed *og, t_parsed *new);
void			manufact_type(t_parsed **tmp, t_point *ptr);
void			link_new_env_node(t_unit_env *og, t_unit_env *new);
void			link_new_rd_node(t_unit_pipe *unit, t_unit_rd *new);
void			link_new_pipe_node(t_unit_head *head, t_unit_pipe *new);

/*
**	Link
*/
int				check_type(char	*type);
int				check_pipe(char *type);
unsigned int	cnt_cmd(t_parsed *parsed);
void			bind_rd_type(t_parsed *type, int *rd);
void			link_to_head(t_point *pck, t_unit_head *head);

/*
**	Free
*/
void			free_package(t_point *pck);
void			free_env_storage(char **storage);

/*
**	Error
*/
int				is_error(char *buf);
int				judge_is_quote_error(int bit);
int				error_is_quot(int bit, char c);
int				check_quote_not_closed(char *buf);
void			control_quote(int *bit, char quot);
int				check_is_backslash_appear(char *buf);

/*
**	End of parsing test session
*/

#endif
