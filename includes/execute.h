/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcha <mcha@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 13:52:11 by mcha              #+#    #+#             */
/*   Updated: 2022/06/02 13:52:12 by mcha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTE_H
# define EXECUTE_H

# include "head.h"
# include <sys/wait.h>
# include <fcntl.h>
# include <string.h>
# include <signal.h>

# define READ_END 0
# define WRITE_END 1
# define EACCESS 2
# define EXIT_FOPEN 1
# define EXIT_CNF 127
# define LL_N_MAX "9223372036854775808"
# define LL_MAX "9223372036854775807"

/* execute.c */
int			execute_cmds(t_unit_head *cmd_list);
int			breed_childs(t_unit_head *cmd_lst);
int			wait_childs(t_unit_head *cmd_lst);

/* execute_builtin.c */
int			check_builtin(t_unit_pipe *cmd);
int			execute_builtin(t_unit_head *cmd_lst, t_unit_pipe *curr_cmd);

/* echo.c */
int			execute_echo(t_unit_pipe *curr_cmd);
int			echo_check_newline(char *option_str);

/* cd.c */
int			execute_cd(t_unit_head *cmd_lst, t_unit_pipe *curr_cmd);
int			cd_home(t_unit_head *cmd_lst);

/* pwd.c */
int			execute_pwd(void);

/* export.c */
int			execute_export(t_unit_head *cmd_lst, t_unit_pipe *curr_cmd);

/* unset.c */
int			execute_unset(t_unit_head *cmd_lst, t_unit_pipe *curr_cmd);

/* export_print.c */
void		sort_env(char **envp);
int			print_env(t_unit_head *cmd_lst);
char		count_export_env(t_unit_head *cmd_lst);
char		*make_export_env_line(t_unit_env *curr);
char		**make_export_env_array(t_unit_head *cmd_lst);

/* export_add.c */
int			check_export_validity(char *str);
int			add_env(t_unit_head *cmd_lst, char *str);
int			find_and_change_env(t_unit_head *cmd_lst, char *str, int i);
t_unit_env	*create_env(char *str);

/* env.c */
char		*make_env_line(t_unit_env *curr);
char		**make_env_array(t_unit_head *cmd_lst);
int			execute_env(t_unit_head *cmd_lst, t_unit_pipe *curr_cmd);

/* exit.c */
int			execute_exit(t_unit_head *cmd_lst, t_unit_pipe *curr_cmd);
long long	check_first_arg(char *str, int *arg_status);

/* execute_child.c */
void		execute_child(t_unit_head *cmd_lst, int pipe_fd[2], \
													int curr_in, int i);
t_unit_pipe	*find_curr_cmd(t_unit_head *cmd_lst, int i);
void		execute_execve(t_unit_head *cmd_lst, t_unit_pipe *curr_cmd);
void		add_path(t_unit_pipe *curr_cmd, char **path);
char		**extract_path(char **envp, t_unit_pipe *curr_cmd);

/* redirect.c */
int			redirect(t_unit_rd *rd);
int			redirect_snin(t_unit_rd *rd);
int			redirect_snout(t_unit_rd *rd);

/* redirect_double.c */
int			redirect_dbin(t_unit_rd *rd);
int			redirect_dbout(t_unit_rd *rd);
int			get_infile(char	*limiter, int curr_out);

/* free_memory.c */
void		free_cmd_lst(t_unit_head *cmd_lst);
void		free_unit_pipe(t_unit_head *cmd_lst);
void		free_unit_env(t_unit_head *cmd_lst);
void		free_array_d2(char	**array_d2);

/* handle_error.c */
int			handle_default_error(char *message);
int			handle_main_process_error(char *message, t_unit_head *cmd_lst);
int			handle_child_process_error(int exit_num, int errnum, char *str);
int			handle_while_generating_error(char *message, \
										t_unit_head *cmd_lst, int i);

/* loader.c */
void		loader(void *int_handler, void *quit_handler);

/* handle_signal.c */
void		sig_handler(int signal);
void		sig_after_readline_handler(int signal);
void		sig_child_handler(int signal);

/* save_stream.c */
void		save_stream(int	*fd_stdin, int *fd_stdout, t_unit_head *cmd_lst);
void		rollback_stream(int fd_stdin, int fd_stdout, t_unit_head *cmd_lst);

#endif