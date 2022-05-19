/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   head.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcha <mcha@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 13:32:42 by mcha              #+#    #+#             */
/*   Updated: 2022/05/19 14:27:10 by mcha             ###   ########.fr       */
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

/*
**	분기가 일어나는 포인트
**	문자열, 공백, 작은 따옴표, 큰 따옴표, 백슬래쉬, 달러, 파이프, 더블 파이프, 세미콜론, <, >, <<, >>
*/
enum e_split_point
{
	STRS,
	SPCE,
	SNQT,
	DBQT,
	BSLA,
	DOLR,
	PIPE,
	DPIP,
	SEMC,
	SNIN,
	SNOU,
	DBIN,
	DBOU
};

/*
**	리다이렉션 종류
**	IN	: < 뒤에 있는 파일 명
**	OUT	: > 뒤에 있는 파일 명
*/
enum e_redirection_type
{
	IN,
	OUT
};

/* 
**	파이프 유닛
**	char		**commands	: 명령어 테이블
**	t_unit_rd	*rd			: redirect 연결 리스트 도입부(시작점) 주소
**	t_unit_pipe	**pp_next	: 다음 파이프 유닛의 주소
*/
typedef struct t_unit_pipe
{
	char		**commands;
	t_unit_rd	*rd;
	t_unit_pipe	*pp_next;
}	t_unit_pipe;

/*
**	리다이렉션 유닛
**	int			rd_type		: 리다이렉션의 타입
**	char		*filename	: 리다이렉션의 파일 명
**	t_unit_rd	*next		: 다음 리다이렉션 요소의 주소
*/
typedef struct t_unit_rd
{
	int			rd_type;
	char		*filename;
	t_unit_rd	*next;
}	t_unit_rd;

#endif
