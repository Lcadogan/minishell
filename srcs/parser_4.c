/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_4.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarmela <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 22:21:08 by acarmela          #+#    #+#             */
/*   Updated: 2021/08/23 22:21:11 by acarmela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	parsing_line4_10(int *m, t_all **all)
{
	(*all)->dollar = try_find((*all)->dollar, (*all)->my_env);
	(*all)->old = (*all)->cmd->argv[*m];
	if (!(*all)->cmd->argv[*m])
	{
		(*all)->cmd->argv[*m] = ft_strdup("");
		(*all)->old = (*all)->cmd->argv[*m];
	}
	(*all)->cmd->argv[*m] = ft_strjoin((*all)->cmd->argv[*m],
			(*all)->dollar);
	free((*all)->old);
	free((*all)->dollar);
	(*all)->dollar = NULL;
	(*all)->old = NULL;
}

void	parsing_line4_1(char *line, int *i, int *m, t_all **all)
{
	if (line[*i] == '$')
	{
		(*i)++;
		while (ft_isalnum(line[*i]) || line[*i] == '_' || line[*i] == '?')
		{
			(*all)->dollar = ft_realloc((*all)->dollar,
					ft_strlen((*all)->dollar) + 2);
			(*all)->dollar = str_add_to_end((*all)->dollar, line[*i]);
			(*i)++;
		}
		parsing_line4_10(m, all);
	}
	else
	{
		(*all)->cmd->argv[*m] = ft_realloc((*all)->cmd->argv[*m],
				ft_strlen((*all)->cmd->argv[*m]) + 2);
		(*all)->cmd->argv[*m] = str_add_to_end((*all)->cmd->argv[*m], line[*i]);
		(*i)++;
	}
}

void	parsing_quote(char *line, int *i, int *m, t_all **all)
{
	while (line[++(*i)] && line[*i] != '\'')
	{
		(*all)->cmd->argv[*m] = ft_realloc((*all)->cmd->argv[*m],
				ft_strlen((*all)->cmd->argv[*m]) + 2);
		(*all)->cmd->argv[*m] = str_add_to_end((*all)->cmd->argv[*m],
				line[*i]);
	}
	if (line[*i] == '\'')
		(*i)++;
}

void	parsing_dquote(char *line, int *i, int *m, t_all **all)
{
	while (line[++(*i)] && line[*i] != '\"')
	{
		(*all)->cmd->argv[*m] = ft_realloc((*all)->cmd->argv[*m],
				ft_strlen((*all)->cmd->argv[*m]) + 2);
		(*all)->cmd->argv[*m] = str_add_to_end((*all)->cmd->argv[*m],
				line[*i]);
	}
	if (line[*i] == '\"')
		(*i)++;
}

void	parsing_line4(char *line, int *i, int *m, t_all **all)
{
	while (line[*i] != ' ' && line[*i] && line[*i] != '>'
		&& line[*i] != '<' && line[*i] != '|')
	{
		(*all)->f = 0;
		if (line[*i] == '\'')
			parsing_quote(line, i, m, all);
		else if (line[*i] == '\"')
			parsing_dquote(line, i, m, all);
		else
			parsing_line4_1(line, i, m, all);
	}
}
