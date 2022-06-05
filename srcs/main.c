/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarmela <acarmela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 22:18:09 by acarmela          #+#    #+#             */
/*   Updated: 2021/08/24 12:52:58 by acarmela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	signal_handler(int sig_num)
{
	int	stat_loc;

	wait(&stat_loc);
	if (stat_loc == sig_num)
	{
		if (sig_num == SIGINT)
		{
			write(1, "\n", 1);
			rl_on_new_line();
			rl_replace_line("", 0);
		}
		else if (sig_num == SIGQUIT)
			ft_putstr_fd("Quit: 3\n", 1);
		g_status = 128 + sig_num;
	}
	else if (sig_num == SIGINT)
	{
		write(1, "\n", 1);
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
		g_status = 1;
	}
}

void	ctrl_d(void)
{
	printf("\033[A");
	printf("minishell> exit\n");
	exit(0);
}

void	initialization(t_all **all, char **env)
{
	signal(SIGINT, signal_handler);
	signal(SIGQUIT, SIG_IGN);
	*all = malloc(sizeof(t_all));
	(*all)->my_env = copy_env(env);
	(*all)->my_env = add_default_variables(&((*all)->my_env));
	(*all)->exit_code = 0;
	g_status = 0;
}

void	execution(t_all **all)
{
	char			*line;

	line = readline("minishell> ");
	if (!line)
		ctrl_d();
	if (!pre_parser(line, all))
	{
		add_history(line);
		signal(SIGQUIT, signal_handler);
		parsing_line(line, all);
		executor(all);
		if ((g_status == 0 && (*all)->exit_code != 0) || (*all)->cmd->next)
			g_status = (*all)->exit_code;
		free(line);
		free_all(all);
	}
	signal(SIGQUIT, SIG_IGN);
}

int	main(int argc, char const *argv[], char *env[])
{
	struct termios	term;
	t_all			*all;

	(void)argc, (void)argv;
	tcgetattr(0, &term);
	term.c_lflag &= ~(ECHOCTL);
	tcsetattr(0, TCSANOW, &term);
	initialization(&all, env);
	while (1)
		execution(&all);
	return (0);
}
