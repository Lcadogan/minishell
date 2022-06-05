/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_5.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarmela <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 20:27:08 by acarmela          #+#    #+#             */
/*   Updated: 2021/08/23 20:27:11 by acarmela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	free_cmd(t_cmd *cmd)
{
	int	i;

	i = -1;
	free(cmd->way);
	while (++i < cmd->count + 1)
		free(cmd->argv[i]);
	free(cmd->argv);
	free(cmd);
}

void	free_all_1(t_all **all)
{
	if ((*all)->dollar)
		free((*all)->dollar);
	if ((*all)->path)
		free((*all)->path);
	if ((*all)->old)
		free((*all)->old);
	if ((*all)->to_red)
		free((*all)->to_red);
}

void	free_all(t_all **all)
{
	t_cmd		*c;
	t_redirect	*r;

	free_all_1(all);
	c = (*all)->cmd;
	while (c)
	{
		c = c->next;
		r = (*all)->cmd->dir;
		while (r)
		{
			r = r->next;
			free((*all)->cmd->dir->argv);
			free((*all)->cmd->dir);
			(*all)->cmd->dir = r;
		}
		free_cmd((*all)->cmd);
		(*all)->cmd = c;
	}
}

int	ft_free(char **ptr, int res)
{
	if (*ptr)
		free(*ptr);
	*ptr = NULL;
	return (res);
}
