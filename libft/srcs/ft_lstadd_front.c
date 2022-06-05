/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarmela <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 12:23:44 by acarmela          #+#    #+#             */
/*   Updated: 2020/11/19 16:27:51 by acarmela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
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
	new->next = a;
	*lst = new;
}
