/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_argv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarmela <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 22:17:57 by acarmela          #+#    #+#             */
/*   Updated: 2021/08/23 22:18:00 by acarmela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	find_argv4(char *line, int *i, int *c)
{
	if (line[*i] == '>' || line[*i] == '<')
	{
		if (line[*i] == '>')
		{
			(*i)++;
			if (line[*i - 1] == '>' && line[*i] == '>')
				(*i)++;
			(*c)++;
		}
		if (line[*i] == '<')
		{
			(*i)++;
			if (line[*i - 1] == '<' && line[*i] == '<')
				(*i)++;
			(*c)++;
		}
	}
}

void	find_argv3(char *line, int *i, int *k)
{
	while (line[*i] != ' ' && line[*i] && line[*i] != '>'
		&& line[*i] != '<' && line[*i] != '|')
	{
		if (line[*i] == '\'')
		{
			while (line[++(*i)] && line[*i] != '\'')
				;
			if (line[*i] == '\'')
				(*i)++;
		}
		if (line[*i] == '\"')
		{
			while (line[++(*i)] && line[*i] != '\"')
				;
			if (line[*i] == '\"')
				(*i)++;
		}
		*k = 1;
		(*i)++;
	}
}

void	find_argv2(char *line, int *i, int *k, int *c)
{
	if (line[*i] == '\"')
	{
		while (line[++(*i)] && line[*i] != '\"')
			*k = 1;
		if (line[*i] == '\"')
			(*i)++;
	}
	find_argv3(line, i, k);
	find_argv4(line, i, c);
}

void	find_argv1(char *line, int *i, int *k)
{
	while (line[*i] == ' ' || line[*i] == '\t')
		(*i)++;
	if (line[*i] == '\'')
	{
		while (line[++(*i)] && line[*i] != '\'')
			*k = 1;
		if (line[*i] == '\'')
			(*i)++;
	}
}

int	find_argv(char *line, int i)
{
	int	n;
	int	k;
	int	c;

	n = 0;
	k = 0;
	c = 0;
	while (line[i] && line[i] != '|')
	{
		find_argv1(line, &i, &k);
		find_argv2(line, &i, &k, &c);
		if (k)
			n++;
		k = 0;
	}
	n = n - c;
	if (n < 0)
		n = 0;
	return (n);
}
