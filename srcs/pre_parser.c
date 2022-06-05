/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarmela <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 22:21:19 by acarmela          #+#    #+#             */
/*   Updated: 2021/08/23 22:21:22 by acarmela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	check_flags(t_all **all, char *line, int n)
{
	if (line[n] == '\'')
		(*all)->flags = (*all)->flags ^ FLG_QUOTES;
	if (line[n] == '\"')
		(*all)->flags = (*all)->flags ^ FLG_DQUOTES;
	if (line[n] == '\\')
		(*all)->flags = (*all)->flags ^ FLG_BACKSLASH;
	if (line[n] == '|' && line[n + 1] == '|')
		(*all)->flags = (*all)->flags ^ FLG_TWOPIPES;
	if (line[n] == ';' && line[n + 1] == ';')
		(*all)->flags = (*all)->flags ^ FLG_TWOSEMICOLON;
	if (line[n] == '|' && line[n + 1] == ';')
		(*all)->flags = (*all)->flags ^ FLG_SEMIPIPE;
	if (line[n] == ';' && line[n + 1] == '|')
		(*all)->flags = (*all)->flags ^ FLG_PIPESEMI;
}

int	pre_parser_2(t_all **all)
{
	if ((*all)->flags & FLG_TWOSEMICOLON)
	{
		printf("minishell: syntax error near unexpected token `;;'\n");
		return (1);
	}
	if ((*all)->flags & FLG_SEMIPIPE)
	{
		printf("minishell: syntax error near unexpected token `;'\n");
		return (1);
	}
	if ((*all)->flags & FLG_PIPESEMI)
	{
		printf("minishell: syntax error near unexpected token `|'\n");
		return (1);
	}
	return (0);
}

int	pre_parser_1(t_all **all)
{
	if ((*all)->flags & FLG_QUOTES)
	{
		printf("minishell: syntax error unclosed quotation `\'\'\n");
		return (1);
	}
	if ((*all)->flags & FLG_DQUOTES)
	{
		printf("minishell: syntax error unclosed double quotation `\"\'\n");
		return (1);
	}
	if ((*all)->flags & FLG_BACKSLASH)
	{
		printf("minishell: syntax error unclosed backslash `\\'\n");
		return (1);
	}
	if ((*all)->flags & FLG_TWOPIPES)
	{
		printf("minishell: syntax error near unexpected token `||'\n");
		return (1);
	}
	return (0);
}

int	pre_parser(char *line, t_all **all)
{
	int	n;

	n = -1;
	(*all)->flags = FLG_NONE;
	if (line[0] == '|')
	{
		if (line[1] == '|')
			printf("minishell: syntax error unexpected token `||'\n");
		else
			printf("minishell: syntax error unexpected token `|'\n");
		return (1);
	}
	while (line[++n])
		check_flags(all, line, n);
	if (pre_parser_1(all))
		return (1);
	if (pre_parser_2(all))
		return (1);
	return (0);
}
