/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_list_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarmela <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 22:18:32 by acarmela          #+#    #+#             */
/*   Updated: 2021/08/23 22:18:36 by acarmela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_redirect	*new_redirect(void)
{
	t_redirect	*new;

	new = malloc(sizeof(t_redirect));
	if (!new)
		return (NULL);
	new->redirect = -1;
	new->next = NULL;
	return (new);
}

void	redirect_back(t_redirect **lst, t_redirect *new)
{
	t_redirect	*p;

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

t_redirect	*redirect_last(t_redirect *lst)
{
	while (lst)
	{
		if (!lst->next)
			return (lst);
		lst = lst->next;
	}
	return (lst);
}
