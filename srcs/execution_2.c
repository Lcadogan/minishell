/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarmela <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 22:17:33 by acarmela          #+#    #+#             */
/*   Updated: 2021/08/23 22:17:40 by acarmela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	perror_and_return(char *argv)
{
	perror(argv);
	return (1);
}

int	do_redirection(int redirect, char *argv, t_fd *std_fd)
{
	int		file;

	file = 0;
	if (redirect == 1)
		file = open(argv, O_WRONLY | O_CREAT | O_TRUNC, 0666);
	else if (redirect == 2)
		file = open(argv, O_WRONLY | O_CREAT | O_APPEND, 0666);
	else if (redirect == 3)
		file = open(argv, O_RDONLY, 0666);
	if (file == -1)
		return (perror_and_return(argv));
	if (redirect == 1 || redirect == 2)
		dup2(file, std_fd->std_output);
	if (redirect == 3)
		dup2(file, std_fd->std_input);
	close(file);
	return (0);
}

void	tmp_fd(int input_fd, int exit_code)
{
	int	file;

	if (exit_code != EXIT_SUCCESS)
	{
		file = open(TMP_FD, O_RDWR | O_CREAT | O_TRUNC, 0666);
		if (file == -1)
			return ;
		dup2(file, input_fd);
		close(file);
	}
}

void	recover_fd(int backup_fd[2], t_fd *fd)
{
	dup2(backup_fd[0], fd->std_input);
	dup2(backup_fd[1], fd->std_output);
	close(backup_fd[0]);
	close(backup_fd[1]);
}

void	init_child(t_all **all, int excode, t_cmd *tmp, int fd_pipe[2])
{
	tmp_fd((*all)->fd.std_input, excode);
	if (tmp->next != NULL)
		dup2(fd_pipe[1], (*all)->fd.std_output);
	close(fd_pipe[1]);
	close(fd_pipe[0]);
	if (is_builtin(tmp) == 1)
	{
		builtins(tmp, &(*all)->my_env, &excode);
		exit(excode);
	}
	else
	{
		if (execve(tmp->way, tmp->argv, (*all)->my_env) == -1)
		{
			write(0, "minishell> ", 6);
			perror(tmp->way);
			exit(127);
		}
	}
}
