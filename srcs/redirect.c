/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarmela <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 22:21:30 by acarmela          #+#    #+#             */
/*   Updated: 2021/08/23 22:21:32 by acarmela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	redirect2(char *line, int *i, t_all **all)
{
	while (line[*i] == ' ')
		(*i)++;
	if (line[*i] == '\'')
	{
		while (line[++(*i)] != '\'' && line[*i])
		{
			(*all)->to_red = ft_realloc((*all)->to_red,
					ft_strlen((*all)->to_red) + 2);
			(*all)->to_red = str_add_to_end((*all)->to_red, line[*i]);
		}
		if (line[*i] == '\'')
			(*i)++;
	}
}

void	redirect_dquote_2(char *line, int *i, t_all **all)
{
	(*all)->to_red = ft_realloc((*all)->to_red,
			ft_strlen((*all)->to_red) + 2);
	(*all)->to_red = str_add_to_end((*all)->to_red, line[(*i)++]);
}

void	redirect_dquote(char *line, int *i, t_all **all)
{
	if (line[*i] == '$')
	{
		(*i)++;
		while (line[*i] != ' ' && line[*i] != '\''
			&& line[*i] != '\"' && line[*i] != '|'
			 && line[*i] != '>' && line[*i] != '<' && line[*i])
		{
			(*all)->dollar = ft_realloc((*all)->dollar,
					ft_strlen((*all)->dollar) + 2);
			(*all)->dollar = str_add_to_end((*all)->dollar, line[*i]);
			(*i)++;
		}
		(*all)->dollar = try_find((*all)->dollar, (*all)->my_env);
		(*all)->old = (*all)->to_red;
		if (!(*all)->to_red)
			(*all)->to_red = ft_strdup("");
		(*all)->to_red = ft_strjoin((*all)->to_red, (*all)->dollar);
		free((*all)->old);
		free((*all)->dollar);
		(*all)->dollar = NULL;
	}
	else
		redirect_dquote_2(line, i, all);
}

void	redirect3(char *line, int *i, t_all **all)
{
	if (line[*i] == '\"')
	{
		(*i)++;
		while (line[*i] != '\"' && line[(*i)])
			redirect_dquote(line, i, all);
		if (line[*i] == '\"')
			(*i)++;
	}
}
