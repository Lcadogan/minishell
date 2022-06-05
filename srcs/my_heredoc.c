/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_heredoc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarmela <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 22:19:45 by acarmela          #+#    #+#             */
/*   Updated: 2021/08/23 22:19:48 by acarmela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	exec_heredoc(char *delimeter, t_all *all)
{
	pid_t	pid;
	int		status;
	int		res;

	res = EXIT_SUCCESS;
	status = 0;
	pid = fork();
	if (pid < 0)
	{
		printf("%s\n", strerror(errno));
		return (71);
	}
	else if (pid == 0)
		my_heredoc(delimeter, all);
	else
	{
		waitpid(pid, &status, 0);
		if (WIFEXITED(status))
			res = WEXITSTATUS(status);
		if (WIFSIGNALED(status) && res != 0)
			res = 128 + WTERMSIG(status);
	}
	if (g_status == 130)
		g_status = 1;
	return (res);
}

int	my_heredoc(char *delimiter, t_all *all)
{
	char	*line;
	int		fd;

	fd = open(TMP_FILE, O_CREAT | O_RDWR | O_TRUNC, 0666);
	signal(SIGINT, SIG_DFL);
	signal(SIGQUIT, SIG_IGN);
	while (1)
	{
		line = readline("> ");
		if (line == NULL || !ft_strncmp(line, delimiter, ft_strlen(line) + 1))
			break ;
		if (line)
			line = parse_dollar(line, &all);
		ft_putstr_fd(line, fd);
		ft_putstr_fd("\n", fd);
		free(line);
	}
	if (line == NULL)
	{
		printf("\033[A");
		printf("> minishell: warning: here-document is delimited by EOF\n");
		exit(0);
	}
	free(line), close(fd);
	exit(0);
}
