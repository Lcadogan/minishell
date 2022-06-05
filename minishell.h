/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarmela <acarmela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 20:19:48 by acarmela          #+#    #+#             */
/*   Updated: 2021/08/24 13:35:07 by acarmela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <unistd.h>
# include <term.h>
# include <string.h>
# include <curses.h>
# include <termcap.h>
# include <stdlib.h>
# include <errno.h>
# include "libft/include/libft.h"
# include <sys/stat.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <fcntl.h>
# include "readline/readline.h"
# include <readline/history.h>
# define TMP_FD ".tmp_fd"
# define TMP_FILE ".heredoc"

# define FLG_NONE			0b00000000
# define FLG_QUOTES			0b00000001 // одинарная кавычка
# define FLG_DQUOTES		0b00000010 // двойная кавычка
# define FLG_SEMIPIPE		0b00000100 // пайп и точка с запятой |;
# define FLG_PIPESEMI		0b00001000 // пайп и точка с запятой |;
# define FLG_TWOPIPES		0b00010000 // два пайпа ||
# define FLG_BACKSLASH		0b00100000 // бекслеш
# define FLG_TWOSEMICOLON	0b01000000 // две точки с запятой ;;

int	g_status;

typedef struct s_fd
{
	int					std_input;
	int					std_output;
}						t_fd;

typedef struct s_redirect{
	int					redirect;
	char				*argv;
	struct s_redirect	*next;
}						t_redirect;

typedef struct s_cmd
{
	char				*way;
	char				**argv;
	int					count;
	t_redirect			*dir;
	struct s_cmd		*next;
}						t_cmd;

typedef struct s_all
{
	char				*dollar;
	char				*path;
	char				**my_env;
	t_cmd				*cmd;
	int					f;
	char				*old;
	char				*to_red;
	int					exit_code;
	unsigned char		flags;
	t_fd				fd;
}						t_all;

/*
*	main.c
*/
void					signal_handler(int sig_num);
void					ctrl_d(void);
void					initialization(t_all **all, char **env);
void					execution(t_all **all);
int						main(int argc, char const *argv[], char *env[]);

/*
*	execution_2.c
*/
int						perror_and_return(char *argv);
int						do_redirection(int redirect, char *argv, t_fd *std_fd);
void					tmp_fd(int input_fd, int exit_code);
void					recover_fd(int backup_fd[2], t_fd *fd);
void					init_child(t_all **all, int excode, \
						t_cmd *tmp, int fd_pipe[2]);

/*
*	execution_3.c
*/
int						scan_redirects(t_redirect *dir, t_fd *std_fd, \
						t_all *all);
int						is_builtin(t_cmd *tmp);
int						builtins(t_cmd *tmp, char ***envp, int *exit_code);
void					execute_binary_1(char **argv, int *excode, pid_t pid, \
						int status);
void					execute_binary(char *b_path, char **argv, \
						char ***envp, int *excode);

/*
*	execution.c
*/
void					call_exec_complex(t_all **all, t_cmd *tmp, \
						int backup_fd[2]);
int						is_number(char *value);
int						call_exec_simple(t_all **all, t_cmd *tmp, \
						int backup_fd[2]);
void					executor(t_all **all);

/*
*	find_argv.c
*/
void					find_argv4(char *line, int *i, int *c);
void					find_argv3(char *line, int *i, int *k);
void					find_argv2(char *line, int *i, int *k, int *c);
void					find_argv1(char *line, int *i, int *k);
int						find_argv(char *line, int i);

/*
*	make_list_2.c
*/
t_redirect				*new_redirect(void);
void					redirect_back(t_redirect **lst, t_redirect *new);
t_redirect				*redirect_last(t_redirect *lst);

/*
*	make_list.c
*/
void					ft_listadd_back(t_cmd **lst, t_cmd *new);
t_cmd					*ft_listnew(void);
t_cmd					*ft_listlast(t_cmd *lst);

/*
*	my_cd.c
*/
char					*get_home_path(char **envp_cp);
int						go_home(char **envp_cp);
int						exec_cd(char **argv, char ***envp_cp);
int						update_pwd(char *old_pwd, char ***envp_cp);
int						my_cd(char **argument, char ***envp_cp);

/*
*	my_echo.c
*/
int						is_flag(char *argv);
int						my_echo(char **argv);

/*
*	my_env.c
*/
int						my_env(char **envp_cp, char **argv);

/*
*	my_exit.c
*/
void					print_error(int count, char **argv);
int						check_num(char *str);
void					exec_exit(char **argv, int *exit_code, int count);
void					my_exit(char **argv, int *exit_code);

/*
*	my_export.c
*/
void					output_sorted_env(char **envp_cp);
int						add_to_envp(char ***envp_cp, char *argument);
int						replace_var(char *key, char **envp_cp, char *argument);
int						exec_export(char **argv, char ***envp_cp);
int						my_export(char **argv, char ***envp_cp);

/*
*	my_heredoc.c
*/
int						exec_heredoc(char *delimeter, t_all *all);
int						my_heredoc(char *delimiter, t_all *all);

/*
*	my_pwd.c
*/
int						my_pwd(void);

/*
*	my_unset.c
*/
int						check_argv(char *argument);
void					remove_var(char ***envp_cp, char *dup_var);
int						my_unset(char ***envp_cp, char **argument);

/*
*	parce_dollar.c
*/
void					parse_dollar2(char **dollar, t_all **all, \
						char **old, char **new);
void					parse_dollar1(char **dollar, char *line, int *i);
void					dollar_init(int *i, char **dollar, \
						char **new, char **old);
char					*parse_dollar(char *line, t_all **all);

/*
*	parcer_2.c
*/
void					parsing_line2_1(char *line, int *i, \
						int *m, t_all **all);
void					parsing_line2_0(char *line, int *i, t_all **all);
void					parsing_line5(char *line, int *i, int *m, t_all **all);

/*
*	parcer_3.c
*/
void					parsing_line3_10(int *m, t_all **all);
void					parsing_line3_1(char *line, int *i, \
						int *m, t_all **all);
void					parsing_line3(char *line, int *i, int *m, t_all **all);

/*
*	parcer_4.c
*/
void					parsing_line4_10(int *m, t_all **all);
void					parsing_line4_1(char *line, int *i, \
	   					int *m, t_all **all);
void					parsing_quote(char *line, int *i, int *m, t_all **all);
void					parsing_dquote(char *line, int *i, int *m, t_all **all);
void					parsing_line4(char *line, int *i, int *m, t_all **all);

/*
*	parcer.c
*/
void					parsing_line2(char *line, int *i, int *m, t_all **all);
void					init_parser(t_all **all);
void					parsing_line(char *line, t_all **all);

/*
*	pre_parser.c
 */
void					check_flags(t_all **all, char *line, int n);
int						pre_parser_2(t_all **all);
int						pre_parser_1(t_all **all);
int						pre_parser(char *line, t_all **all);

/*
*	redirect2.c
*/
void					redirect4_1(char *line, int *i, t_all **all);
void					redirect_quote(char *line, int *i, t_all **all);
void					redirect4(char *line, int *i, t_all **all);

/*
*	redirect.c
*/
void					redirect2(char *line, int *i, t_all **all);
void					redirect_dquote_2(char *line, int *i, t_all **all);
void					redirect_dquote(char *line, int *i, t_all **all);
void					redirect3(char *line, int *i, t_all **all);

/*
*	utils_2.c
*/
int						is_equal(char *path, char *env);
char					*ft_strcpy(char *dst, char *src);
char					*ft_realloc(char *ptr, size_t size);
char					*str_add_to_end(char *str, char c);

/*
*	utils_3.c
*/
void					try_find2(char *path, char **env, int *n, char **str);
char					*try_find(char *path, char **env);
void					make_null(char ***argv, int n);
void					clear_arr_2x(char **a);
char					*find_binary(char *cmnd, char *paths);

/*
*	utils_4.c
*/
int						ft_strcmp(char *s1, char *s2);
int						is_minishell(char *line);
char					**copy_env(char **env);
char					*increase_sh_level(char *value);
char					**add_default_variables(char ***envp);

/*
*	utils_5.c
*/
void					free_cmd(t_cmd *cmd);
void					free_all_1(t_all **all);
void					free_all(t_all **all);
int						ft_free(char **ptr, int res);

/*
*	utils_6.c
*/
char					*get_absolute_path(char **envp_cp, char *relative_path);
int						count_arguments(char **argv);
void					add_to_end(char ***src, char *addback);
int						set_value_arr_2x(char *str, char ***arr);
char					**check_key(char **envs, char *key);

/*
*	utils_7.c
*/
int						check_var_validity(char *argument);
void					sort_array_2x(char **array);
void					print_arr_2x(char **array);

/*
*	utils.c
*/
char					**copy_arrays_2x(char **src_arr);
int						fail(char *str, int res);
int						count_envp(char **envp_cp);
char					*check_arg(char **envp_cp, char **key);
char					*get_value(char **envp_cp, char *key);

// void					rl_replace_line(char[1], ...);
void					rl_replace_line(const char *str, int i);
#endif
