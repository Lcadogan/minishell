/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution_3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarmela <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 22:17:47 by acarmela          #+#    #+#             */
/*   Updated: 2021/08/23 22:17:51 by acarmela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	scan_redirects(t_redirect *dir, t_fd *std_fd, t_all *all)
{
	t_redirect		*tmp;
	int				file;
	int				exit_code;

	tmp = dir;
	if (!(tmp))
		return (EXIT_SUCCESS);
	while (tmp)
	{
		if (tmp->redirect != 4)
		{
			if (do_redirection(tmp->redirect, tmp->argv, std_fd) != 0)
				return (1);
		}
		else
		{
			exit_code = exec_heredoc(tmp->argv, all);
			if (exit_code != EXIT_SUCCESS)
				return (exit_code);
			file = open(TMP_FILE, O_RDONLY, 0666);
			dup2(file, std_fd->std_input), close(file), unlink(TMP_FILE);
		}
		tmp = tmp->next;
	}
	return (0);
}

int	is_builtin(t_cmd *tmp)
{
	if (!(ft_strncmp(tmp->argv[0], "echo", ft_strlen(tmp->argv[0]) + 1)))
		return (1);
	else if (!(ft_strncmp(tmp->argv[0], "cd", ft_strlen(tmp->argv[0]) + 1)))
		return (1);
	else if (!(ft_strncmp(tmp->argv[0], "pwd", ft_strlen(tmp->argv[0]) + 1)))
		return (1);
	else if (!(ft_strncmp(tmp->argv[0], "export", ft_strlen(tmp->argv[0]) + 1)))
		return (1);
	else if (!(ft_strncmp(tmp->argv[0], "unset", ft_strlen(tmp->argv[0]) + 1)))
		return (1);
	else if (!(ft_strncmp(tmp->argv[0], "env", ft_strlen(tmp->argv[0]) + 1)))
		return (1);
	else if (!(ft_strncmp(tmp->argv[0], "exit", ft_strlen(tmp->argv[0]) + 1)))
		return (1);
	return (0);
}

int	builtins(t_cmd *tmp, char ***envp, int *exit_code)
{
	if (!(ft_strncmp(tmp->argv[0], "echo", ft_strlen(tmp->argv[0]) + 1)))
		*exit_code = (my_echo(tmp->argv));
	else if (!(ft_strncmp(tmp->argv[0], "cd", ft_strlen(tmp->argv[0]) + 1)))
		*exit_code = (my_cd(tmp->argv, envp));
	else if (!(ft_strncmp(tmp->argv[0], "pwd", ft_strlen(tmp->argv[0]) + 1)))
		*exit_code = (my_pwd());
	else if (!(ft_strncmp(tmp->argv[0], "export", ft_strlen(tmp->argv[0]) + 1)))
		*exit_code = (my_export(tmp->argv, envp));
	else if (!(ft_strncmp(tmp->argv[0], "unset", ft_strlen(tmp->argv[0]) + 1)))
		*exit_code = (my_unset(envp, tmp->argv));
	else if (!(ft_strncmp(tmp->argv[0], "env", ft_strlen(tmp->argv[0]) + 1)))
		*exit_code = my_env(*envp, tmp->argv);
	else if (!(ft_strncmp(tmp->argv[0], "exit", ft_strlen(tmp->argv[0]) + 1)))
		my_exit(tmp->argv, exit_code);
	return (0);
}

void	execute_binary_1(char **argv, int *excode, pid_t pid, int status)
{
	if (is_minishell(argv[0]))
		signal(SIGINT, SIG_IGN);
	waitpid(pid, &status, 0);
	signal(SIGINT, signal_handler);
	if (WIFEXITED(status))
		*excode = WEXITSTATUS(status);
}

void	execute_binary(char *b_path, char **argv, char ***envp, int *excode)
{
	pid_t			pid;
	int				status;

	pid = fork();
	status = 0;
	if (pid < 0)
	{
		printf("%s\n", strerror(errno));
		*excode = 71;
	}
	if (pid == 0)
	{
		execve(b_path, argv, *envp);
		if (b_path == NULL)
		{
			if (*argv == NULL)
				printf("minishell> : command not found\n");
			else
				printf("minishell> %s: command not found\n", *argv);
		}
		exit(127);
	}
	else
		execute_binary_1(argv, excode, pid, status);
}
