/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarmela <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 21:30:53 by acarmela          #+#    #+#             */
/*   Updated: 2020/11/20 10:30:15 by acarmela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*a;

	if (!lst || !new)
		return ;
	if (*lst == 0)
	{
		*lst = new;
		new->next = NULL;
		return ;
	}
	a = *lst;
	a = ft_lstlast(a);
	a->next = new;
}
