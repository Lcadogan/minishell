/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarmela <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 22:18:19 by acarmela          #+#    #+#             */
/*   Updated: 2021/08/23 22:18:24 by acarmela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_listadd_back(t_cmd **lst, t_cmd *new)
{
	t_cmd	*p;

	if (lst == NULL)
		return ;
	p = *lst;
	if (p == NULL)
	{
		*lst = new;
		return ;
	}
	while (p->next != NULL)
		p = p->next;
	p->next = new;
}

t_cmd	*ft_listnew(void)
{
	t_cmd	*new;

	new = malloc(sizeof(t_cmd));
	if (!new)
		return (NULL);
	new->next = NULL;
	new->dir = NULL;
	return (new);
}

t_cmd	*ft_listlast(t_cmd *lst)
{
	while (lst)
	{
		if (!lst->next)
			return (lst);
		lst = lst->next;
	}
	return (lst);
}
