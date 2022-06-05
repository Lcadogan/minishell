/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarmela <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 22:20:40 by acarmela          #+#    #+#             */
/*   Updated: 2021/08/23 22:20:44 by acarmela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	parsing_line2(char *line, int *i, int *m, t_all **all)
{
	while (line[*i] == ' ' || line[*i] == '\t')
	{
		(*i)++;
		(*all)->f = 0;
	}
	if ((*all)->f == 0 && (*all)->cmd->argv[*m] != NULL)
	{
		(*m)++;
		(*all)->f = 1;
	}
	if (line[*i] == '\'')
	{
		while (line[++(*i)] != '\'' && line[*i])
		{
			(*all)->cmd->argv[*m] = ft_realloc((*all)->cmd->argv[*m],
					 	 		 ft_strlen((*all)->cmd->argv[*m]) + 2);
			(*all)->cmd->argv[*m] = str_add_to_end((*all)->cmd->argv[*m],
					   line[*i]);
			(*all)->f = 1;
		}
		if (line[*i] == '\'')
			(*i)++;
	}
}

void	init_parser(t_all **all)
{
	(*all)->dollar = NULL;
	(*all)->f = 0;
	(*all)->to_red = NULL;
	(*all)->cmd = ft_listnew();
}

void	parsing_line(char *line, t_all **all)
{
	t_cmd	*first;
	int		i;
	int		m;

	i = 0;
	m = 0;
	init_parser(all);
	first = (*all)->cmd;
	(*all)->old = NULL;
	(*all)->cmd->count = find_argv(line, i);
	(*all)->cmd->argv = (char **)malloc(sizeof(char *)
			* ((*all)->cmd->count + 1));
	(*all)->cmd->way = NULL;
	make_null(&(*all)->cmd->argv, (*all)->cmd->count);
	(*all)->path = try_find(ft_strdup("PATH"), (*all)->my_env);
	while (line[i])
	{
		parsing_line2(line, &i, &m, all);
		parsing_line3(line, &i, &m, all);
		parsing_line4(line, &i, &m, all);
		parsing_line5(line, &i, &m, all);
	}
	if (!(*all)->cmd->way)
		(*all)->cmd->way = find_binary((*all)->cmd->argv[0], (*all)->path);
	(*all)->cmd = first;
}
