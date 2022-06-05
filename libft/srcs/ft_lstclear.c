/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarmela <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 15:14:25 by acarmela          #+#    #+#             */
/*   Updated: 2020/11/21 14:43:44 by acarmela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*a;

	if (lst)
	{
		while (*lst)
		{
			a = *lst;
			*lst = (*lst)->next;
			del(a->content);
			free(a);
		}
	}
	*lst = NULL;
}
